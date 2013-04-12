/*
Copyright (c) 2013, Florent V. <vicos51-at-gmail.com>
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met: 

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer. 
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution. 
   
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "udplistener.h"

const QHostAddress UdpListener::IPV6_DISCOVERY_MCAST("ff02::c");
const QHostAddress UdpListener::IPV4_DISCOVERY_MCAST("239.255.255.250");

UdpListener::UdpListener(QNetworkInterface networkInterface,
                         QHostAddress interfaceAddress,
                         QObject *parent) :
    QObject(parent),
    _netIf(networkInterface),
    _ifAddr(interfaceAddress),
    _mSocket(this)
{
    _mSocket.bind(_ifAddr, 0, QAbstractSocket::ReuseAddressHint);
    _mSocket.setMulticastInterface(_netIf);

    if(_ifAddr.protocol() == QAbstractSocket::IPv6Protocol)
    {
        _mSocket.joinMulticastGroup(IPV6_DISCOVERY_MCAST, _netIf);
    }
    else if (_ifAddr.protocol() == QAbstractSocket::IPv4Protocol)
    {
        _mSocket.joinMulticastGroup(IPV4_DISCOVERY_MCAST, _netIf);
    }

    qDebug() << "UDP listener start to listen on " << _ifAddr.toString();
}

UdpListener::~UdpListener()
{
    if(_ifAddr.protocol() == QAbstractSocket::IPv6Protocol)
    {
        _mSocket.leaveMulticastGroup(IPV6_DISCOVERY_MCAST, _netIf);
    }
    else if (_ifAddr.protocol() == QAbstractSocket::IPv4Protocol)
    {
        _mSocket.leaveMulticastGroup(IPV4_DISCOVERY_MCAST, _netIf);
    }

    _mSocket.close();

    qDebug() << "UDP listener stop to listen from " << _ifAddr.toString();
}
