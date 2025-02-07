// MIT License

#include "TankBattle.h"
#include "Public/TankTrack.h"
#include "Public/TankMovementComponent.h"



void UTankMovementComponent::Initialize(UTankTrack *LeftTrackToSet, UTankTrack *RightTrackToSet) {
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw) {
	if (!LeftTrack || !RightTrack) return;
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);

	// TODO prevent speed due to double input controls

}

void UTankMovementComponent::IntendTurnRight(float Throw) {
	if (!LeftTrack || !RightTrack) return;
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);

	// TODO prevent speed due to double input controls

}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) {
	UE_LOG(LogTemp, Warning, TEXT("Tank: %s, MoveVelocity: %s"), *GetOwner()->GetName(), *MoveVelocity.GetSafeNormal().ToString());

	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	auto ForwardThrust = FVector::DotProduct(TankForward, AIForwardIntention);
	auto Turn = FVector::CrossProduct(TankForward, AIForwardIntention);

	IntendMoveForward(ForwardThrust);
	IntendTurnRight(Turn.Z);
}
