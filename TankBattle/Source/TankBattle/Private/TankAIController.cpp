// MIT License

#include "TankBattle.h"
#include "Public/Tank.h"
#include "Public/TankAIController.h"


void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = true;
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto CurrentTank = Cast<ATank>(GetPawn());
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (PlayerTank && CurrentTank) {
		MoveToActor(PlayerTank, AcceptanceRadius);

		CurrentTank->AimAt(PlayerTank->GetActorLocation());

		CurrentTank->Fire();

	}
}
