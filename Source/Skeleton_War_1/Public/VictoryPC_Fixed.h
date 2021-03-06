/*

By Rama

*/
#pragma once

//HTTP
#include "Http.h"
#include "VictoryPC_Fixed.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(VictoryPC_FixedLog, Log, All);

UCLASS()
class SKELETON_WAR_1_API AVictoryPC_Fixed : public APlayerController {
    GENERATED_UCLASS_BODY()


        /** This node relies on http://api.ipify.org, so if this node ever stops working, check out http://api.ipify.org.  Returns false if the operation could not occur because HTTP module was not loaded or unable to process request. */
        UFUNCTION(BlueprintCallable, Category = "Victory PC")
        bool VictoryPC_GetMyIP_SendRequest();

    /** Implement this event to receive your IP once the request is processed! This requires that your computer has a live internet connection */
    UFUNCTION(BlueprintImplementableEvent, Category = "Victory PC", meta = (DisplayName = "VictoryPC ~ Get My IP (Fixed) ~ Data Received!"))
        void VictoryPC_GetMyIP_DataReceived(const FString& YourIP);

    void HTTPOnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
};