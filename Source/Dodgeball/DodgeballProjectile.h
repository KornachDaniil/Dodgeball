// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "DodgeballProjectile.generated.h"

UCLASS()
class DODGEBALL_API ADodgeballProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADodgeballProjectile();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Dodgeball, meta=(AllowPrivateAccess = "true"))
	USphereComponent* SphereComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Dodgeball, meta=(AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category=Damage)
	float Damage = 34.0f;

	UPROPERTY(EditAnywhere, Category=Sound)
	USoundBase* BounceSound;

	UPROPERTY(EditAnywhere, Category=Damage)
	USoundBase* DamageSound;

	UPROPERTY(EditAnywhere, Category=Sound)
	USoundAttenuation* BounceSoundAttenuation;

	UPROPERTY(EditAnywhere, Category=Particles)
	UParticleSystem* HitParticles;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE UProjectileMovementComponent* GetProjectileMovementComponent() const
	{
		return ProjectileMovement;		
	}
	
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse
		, const FHitResult& Hit);
	
};
