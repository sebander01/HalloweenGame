#include "PlayerMovement.h"
#include "Blueprint/WidgetLayoutLibrary.h"
float currentSpeed;
float baseSpeed;
float maxSpeed;
UMeshComponent* Body;
float sprintSpeed;
//Private in the .h
bool isSprinting = false;

// Sets default values
APlayerMovement::APlayerMovement()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerMovement::BeginPlay()
{
	Super::BeginPlay();
	//Default the current speed to the base speed we will change this to the sprint speed and back to base speed as needed
	currentSpeed = baseSpeed;
	
}

// Called every frame
void APlayerMovement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerMovement::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

/// <summary>
/// Allows the player to move forward
/// </summary>
void APlayerMovement::MoveForward()
{
	//Checks if the player is within the speed limit for standard movement
	if (Body->GetPhysicsLinearVelocity().X <= maxSpeed)
	{
		//Adds an impulse force to allow us to move the player
		Body->AddImpulse(FVector(currentSpeed, 0, 0));
	}
}

/// <summary>
/// Allows the player to move backwards
/// </summary>
void APlayerMovement::MoveBackward()
{
	//Checks if the player is within the speed limit for standard movement
	if (Body->GetPhysicsLinearVelocity().X <= maxSpeed)
	{
		//Adds an impulse force to allow us to move the player
		Body->AddImpulse(FVector(-currentSpeed, 0, 0));
	}
}

/// <summary>
/// Allows the player to move right
/// </summary>
void APlayerMovement::MoveRight()
{
	//Checks if the player is within the speed limit for standard movement
	if (Body->GetPhysicsLinearVelocity().Y <= maxSpeed)
	{
		//Adds an impulse force to allow us to move the player
		Body->AddImpulse(FVector(0, currentSpeed, 0));
	}
}

/// <summary>
/// Allows the player to move left
/// </summary>
void APlayerMovement::MoveLeft()
{
	//Checks if the player is within the speed limit for standard movement
	if (Body->GetPhysicsLinearVelocity().Y <= maxSpeed)
	{
		//Adds an impulse force to allow us to move the player
		Body->AddImpulse(FVector(0, -currentSpeed, 0));
	}
}

void APlayerMovement::Sprint()
{
	//If we are ending sprinting
	if (isSprinting)
	{
		currentSpeed = baseSpeed;
		isSprinting = false;
	}
	//If we are starting sprinting
	else if (!isSprinting)
	{
		currentSpeed = sprintSpeed;
		isSprinting = true;
	}
}

