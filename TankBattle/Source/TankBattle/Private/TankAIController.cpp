// MIT License

#include "TankBattle.h"
#include "Public/TankAIController.h"


void ATankAIController::BeginPlay() {
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