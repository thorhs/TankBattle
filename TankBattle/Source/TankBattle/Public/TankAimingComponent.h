// MIT License

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKBATTLE_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel *BarrelToSet);

	// TODO add SetTurretReference

	void AimAt(FVector HitLocation, float LaunchSpeed);

private:
	UTankBarrel *Barrel = nullptr;

	void MoveBarrel(FVector AimDirection);
	
};
