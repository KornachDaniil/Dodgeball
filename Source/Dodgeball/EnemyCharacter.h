// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DodgeballProjectile.h"
#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class DODGEBALL_API AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Dodgeball)
	TSubclassOf<ADodgeballProjectile> DodgeballClass;
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=LookAt, meta=(AllowPrivateAccess = "true"));
	USceneComponent* SightSource;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	void ThrowDodgeball() const;
	
	FTimerHandle ThrowTimerHandle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Fire)
	float ThrowingInterval = 2.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Fire)
	float ThrowingDelay = 0.5f;
	
	bool bCanSeePlayer = false;
	bool bPreviousCanSeePlayer = false;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Перемещена в BlueprintFunctionLibrary
	// bool CanSeeActor(const AActor* TargetActor) const;
	
	bool LookAtActor(AActor* TargetActor);
};
