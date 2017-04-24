// MIT License

#include "TankBattle.h"
#include "Public/TankTrack.h"



void UTankTrack::SetThrottle(float Throttle) {
	Throttle = FMath::Clamp<float>(Throttle, -1, +1);

	UE_LOG(LogTemp, Warning, TEXT("Track %s throttle set to %f"), *GetName(), Throttle);
}

