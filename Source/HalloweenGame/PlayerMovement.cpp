#include "PlayerMovement.h"
#include "Blueprint/WidgetLayoutLibrary.h"
float currentSpeed;
float baseSpeed;
float maxSpeed;
UMeshComponent* Body;
float sprintSpeed;
//Private in the .h
bool isSprinting = false;

//Last mouse position
FVector2D lastMPos;

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

/// <summary>
/// A method that allows for movement in the first person camera based on the mouse position of the player
/// </summary>
void APlayerMovement::MoveFirstPersonCamera(UMeshComponent* cam, float cameraSpeed)
{
	//Get the mouse position
	FVector2D mousePos;
	GEngine->GameViewport->GetMousePosition(mousePos);
	PrintDebug(mousePos);

#pragma region Camera movement
	//This focuses on just the camera movement individually

	//If we turn the camera right
	if (mousePos.X < lastMPos.X && mousePos.X)
	{
		//Add to the rotation so that we move the camera right
		cam->AddLocalRotation(FRotator(0, -cameraSpeed, 0));
	}
	//If we turn the camera left
	else if (mousePos.X > lastMPos.X)
	{
		//Add to the rotation the same way as we do for going right but with a - so we subtract
		cam->AddLocalRotation(FRotator(0, cameraSpeed, 0));
	}

	//If we point the camera up
	if (mousePos.Y < lastMPos.Y)
	{
		//Add to the rotation so that we move the camera up
		cam->AddLocalRotation(FRotator(cameraSpeed, 0, 0));
	}
	//If we point the camera down
	else if (mousePos.Y > lastMPos.Y)
	{
		//Add a negative number to the mose position so that we move the opposite direction
		cam->AddLocalRotation(FRotator(-cameraSpeed, 0, 0));
	}

	lastMPos = mousePos;

#pragma endregion
}

/// <summary>
/// Delete later this is for my sanity so I don't have to keep retyping this
/// </summary>
/// <param name="message"></param>
void APlayerMovement::PrintDebug(FVector2D message)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, message.ToString());
}

