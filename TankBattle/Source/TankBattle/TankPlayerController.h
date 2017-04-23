// MIT License

#pragma once

#include "Public/Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANKBATTLE_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Will start the tank moving the barrel towards where the crosshair intersects the world
	void AimTowardsCrosshair()
};
