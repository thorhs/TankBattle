// MIT License

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANKBATTLE_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);

	// This is max force per trac, in newtons
	UPROPERTY(EditDefaultsOnly, Category = Movement)
	float TrackMaxDrivingForce = 400000.f; /// Assume 40t tank and 1g acceleration
	
};
