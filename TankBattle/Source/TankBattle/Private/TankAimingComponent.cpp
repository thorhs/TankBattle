// MIT License

#include "TankBattle.h"
#include "../Public/TankAimingComponent.h"
#include "Public/TankBarrel.h"
#include "Public/TankTurret.h"



// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret * TurretToSet)
{
	Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel || !Turret) return;

	FVector LaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	
	if (UGameplayStatics::SuggestProjectileVelocity(
			this,
			LaunchVelocity,
			StartLocation,
			HitLocation,
			LaunchSpeed,
			false,
			0.0f,
			0.0f,
			ESuggestProjVelocityTraceOption::DoNotTrace)
		)
	{
		auto AimDirection = LaunchVelocity.GetSafeNormal();
		MoveBarrel(AimDirection);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Unable to get an aiming solution"));
	}

}

void UTankAimingComponent::MoveBarrel(FVector AimDirection) {
	// Find rotation required
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	// Rotate turret to required angle


	// Raise barrel to required angle
	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->Rotate(DeltaRotator.Yaw);
}

