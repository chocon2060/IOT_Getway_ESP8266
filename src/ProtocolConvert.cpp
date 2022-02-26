#include"ProtocolConvert.h"
void ProtocolConvert::serverToloraConvert(String msgPayload){
    lastpoint = msgPayload.indexOf("{") + 1;
    nextpoint = msgPayload.indexOf(",");
    payloadSub[0] =  msgPayload.substring(lastpoint,nextpoint);

    lastpoint = payloadSub[0].indexOf('"') + 1;
    nextpoint = payloadSub[0].indexOf('"',lastpoint);
    payloadSub[1] = payloadSub[0].substring(lastpoint,nextpoint);
    if(payloadSub[1] == "Client")
    {
        ProtocolConvert::serverClientCmd(msgPayload);
    }
    else if(payloadSub[1] == "Getway")
    {
        ProtocolConvert::serverGetwayCmd(msgPayload);
    }
}

void ProtocolConvert::serverClientCmd(String msgPayload){
    lastpoint = msgPayload.indexOf("{") + 1;
    nextpoint = msgPayload.indexOf(",");
    payloadSub[0] =  msgPayload.substring(lastpoint,nextpoint);

    lastpoint = payloadSub[0].indexOf(':') + 1;
    nextpoint = payloadSub[0].indexOf(',',lastpoint);
    payloadSub[1] = payloadSub[0].substring(lastpoint,nextpoint);
    // check string is number 
    if(!ProtocolConvert::isNumber( payloadSub[1])){
        return;
    }
    



}

bool ProtocolConvert::isNumber(String str){

    for (int i = 0; i < str.length(); i++){
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;    
}
