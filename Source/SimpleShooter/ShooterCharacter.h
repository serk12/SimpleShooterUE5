// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"


class AGun;

UCLASS()
class SIMPLESHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	void MoveForward(float axisValue_);
	void MoveRight(float axisValue_);
	void LookUpRate(float axisValue_);
	void LookRightRate(float axisValue_);

	UPROPERTY(EditAnywhere)
	float mRotationRate = 10.0f;

	UPROPERTY(EditDefaultsOnly)
	float mMaxHealt = 100.0f;

	UPROPERTY(VisibleAnywhere)
	float mCurrentHealt;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGun> mGunClass;

	UPROPERTY()
	AGun* mGun;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this character's properties
	AShooterCharacter();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintPure)
	float GetHealth() const { return mCurrentHealt; }

	void Shoot();
};
