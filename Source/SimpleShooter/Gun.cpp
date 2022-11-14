// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"

#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("root"));
	SetRootComponent(mRootComponent);

	mMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("mesh"));
	mMesh->SetupAttachment(mRootComponent);
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGun::PullTrigger()
{
	UGameplayStatics::SpawnEmitterAttached(mMuzzleFlash, mMesh, TEXT("MuzzleFlashSocket"));
	APawn* ownerPawn = Cast<APawn>(GetOwner());
	if (ownerPawn == nullptr) return;
	AController* ownerController = ownerPawn->GetController();
	if (ownerController == nullptr) return;
	FVector location;
	FRotator rotation;
	ownerController->GetPlayerViewPoint(location, rotation);
	FVector endLocation = location + rotation.Vector() * mMaxRange; 

	// DrawDebugCamera(GetWorld(), location, rotation, 90, 2, FColor::Red, true);

	FHitResult hit;
	FCollisionQueryParams params;
	params.AddIgnoredActor(this);
	params.AddIgnoredActor(GetOwner());
	bool result = GetWorld()->LineTraceSingleByChannel(hit, location, endLocation, ECollisionChannel::ECC_GameTraceChannel1, params);
	if (result) {
		// DrawDebugPoint(GetWorld(), hit.Location, 20, FColor::Red, true);
		FVector shotDirection = -rotation.Vector();
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), mHitFlash, hit.Location, shotDirection.Rotation());
		FPointDamageEvent damageEvent(mDamage, hit, shotDirection, nullptr);
		AActor* hitActor = hit.GetActor();
		if (hitActor != nullptr) {
			hitActor->TakeDamage(mDamage, damageEvent, ownerController, this);
		}

	}
}
