// MIT License

#include "TankBattle.h"
#include "Public/TankBarrel.h"




void UTankBarrel::Elevate(float RelativeSpeed) {
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.f, 1.f);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(Elevation, 0.f, 0.f));
}