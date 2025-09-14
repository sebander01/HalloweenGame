// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerMovement.generated.h"

UCLASS()
class HALLOWEENGAME_API APlayerMovement : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerMovement();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GroundMovementVariables")
	float baseSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GroundMovementVariables")
	float maxSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GroundMovementVariables")
	UMeshComponent* Body;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GroundMovementVariables")
	float sprintSpeed;

private:
	UPROPERTY(VisibleAnywhere, Category = "GroundMovementVariables")
	bool isSprinting;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "GroundMovement")
	void MoveForward();

	UFUNCTION(BlueprintCallable, Category = "GroundMovement")
	void MoveBackward();

	UFUNCTION(BlueprintCallable, Category = "GroundMovement")
	void MoveRight();

	UFUNCTION(BlueprintCallable, Category = "GroundMovement")
	void MoveLeft();

	UFUNCTION(BlueprintCallable, Category = "GroundMovement")
	void Sprint();
};
