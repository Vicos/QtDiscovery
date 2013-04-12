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

#include "xmlsoapmessage.h"

const QString XmlSoapMessage::SOAP_NS = "http://www.w3.org/2003/05/soap-envelope";

XmlSoapMessage::XmlSoapMessage(QObject *parent) :
    QObject(parent)
{
}

QDomElement XmlSoapMessage::buildMessage(QDomDocument &doc,
                                         QDomElement header,
                                         QDomElement body)
{
    QDomElement envelopeElm = doc.createElementNS(SOAP_NS, "soap:Envelope");
    QDomElement headerElm = doc.createElement("soap:Header");
    QDomElement bodyElm = doc.createElement("soap:Body");

    headerElm.appendChild(header);
    bodyElm.appendChild(body);
    envelopeElm.appendChild(headerElm);
    envelopeElm.appendChild(bodyElm);

    return(envelopeElm);
}
