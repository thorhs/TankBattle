// MIT License

#include "TankBattle.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay() {
	auto ControlledTank = GetControlledTank();

	if (!ControlledTank) {
		UE_LOG(LogTemp, Error, TEXT("ATankAIController is not possessing a tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("ATankAIController is controlling tank: %s"), *ControlledTank->GetName());
	}
}

ATank *ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}