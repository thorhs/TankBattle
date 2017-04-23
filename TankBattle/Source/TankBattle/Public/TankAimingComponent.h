// MIT License

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKBATTLE_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UStaticMeshComponent *BarrelToSet);

	// TODO add SetTurretReference

	void AimAt(FVector HitLocation, float LaunchSpeed);

private:
	UStaticMeshComponent *Barrel = nullptr;

	void MoveBarrel(FVector AimDirection);
	
};
