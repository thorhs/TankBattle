// MIT License

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANKBATTLE_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward movement, +1 is max upward movement
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesPerSecond = 10.0f;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MinElevationDegrees = 0.0f;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxElevationDegrees = 40.0f;


};
