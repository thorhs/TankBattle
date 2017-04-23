// MIT License

#pragma once

#include "Public/Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class TANKBATTLE_API ATankAIController : public AAIController
{
	GENERATED_BODY()


	virtual void BeginPlay() override;

	ATank *GetControlledTank() const;
	
	
};
