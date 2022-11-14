// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class SIMPLESHOOTER_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void PullTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	class USceneComponent* mRootComponent;

	UPROPERTY(VisibleAnywhere)
	class USkeletalMeshComponent* mMesh;

	UPROPERTY(EditAnywhere)
	UParticleSystem* mMuzzleFlash;
	
	UPROPERTY(EditAnywhere)
	UParticleSystem* mHitFlash;

	UPROPERTY(EditAnywhere)
	float mMaxRange = 1000.0f; 

	UPROPERTY(EditAnywhere)
	float mDamage = 5.0f; 
};
