// MIT License

#include "TankBattle.h"
#include "Public/Tank.h"
#include "Public/TankAIController.h"


void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = true;

	auto ControlledTank = GetControlledTank();
	auto PlayerController = GetPlayerTank();

	if (!PlayerController) {
		UE_LOG(LogTemp, Error, TEXT("ATankAIController did not find the player"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("ATankAIController found player: %s"), *PlayerController->GetName());
	}
}

ATank *ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank *ATankAIController::GetPlayerTank() const {
	auto PlayerController = GetWorld()->GetFirstPlayerController()->GetPawn();

	return Cast<ATank>(PlayerController);
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto CurrentTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();

	if (PlayerTank && CurrentTank)
		CurrentTank->AimAt(PlayerTank->GetActorLocation());

}
