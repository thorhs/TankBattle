// MIT License

#include "TankBattle.h"
#include "TankPlayerController.h"




void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	auto Tank = GetControlledTank();
	if (Tank) {
		UE_LOG(LogTemp, Warning, TEXT("ATankPlayerController is controlling tank: %s"), *Tank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("ATankPlayerController is unable to get controlled tank"));
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}