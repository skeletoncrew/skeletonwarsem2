/*

By Rama

*/

#include "Skeleton_War_1.h"
#include "VictoryPC_Fixed.h"

DEFINE_LOG_CATEGORY(VictoryPC_FixedLog)

//////////////////////////////////////////////////////////////////////////
// AVictoryPC_Fixed

AVictoryPC_Fixed::AVictoryPC_Fixed(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer) {

}

bool AVictoryPC_Fixed::VictoryPC_GetMyIP_SendRequest() {
    FHttpModule* Http = &FHttpModule::Get();

    if (!Http) {
        return false;
    }

    if (!Http->IsHttpEnabled()) {
        return false;
    }
    //~~~~~~~~~~~~~~~~~~~

    FString TargetHost = "http://api.ipify.org";
    TSharedRef < IHttpRequest > Request = Http->CreateRequest();
    Request->SetVerb("GET");
    Request->SetURL(TargetHost);
    Request->SetHeader("User-Agent", "VictoryBPLibrary/1.0");
    Request->SetHeader("Content-Type", "text/html");

    Request->OnProcessRequestComplete().BindUObject(this, &AVictoryPC_Fixed::HTTPOnResponseReceived);
    if (!Request->ProcessRequest()) {
        return false;
    }

    return true;
}

void AVictoryPC_Fixed::HTTPOnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
    FString response = "";
    if (bWasSuccessful)
        response = Response->GetContentAsString();

    this->VictoryPC_GetMyIP_DataReceived(response);
}
