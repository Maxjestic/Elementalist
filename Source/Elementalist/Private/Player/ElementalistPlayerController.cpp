// Copyright Maxjestic


#include "Player/ElementalistPlayerController.h"

#include "InputAction.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void AElementalistPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(ElementalistContext)

	// Default Input Component class set in Project Settings > Input > Default Classes
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
		GetLocalPlayer() ))
	{
		Subsystem->AddMappingContext( ElementalistContext, 0 );
	}
}

void AElementalistPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(InputComponent);
	
	Input->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AElementalistPlayerController::Move);
	Input->BindAction(LookAction, ETriggerEvent::Triggered, this, &AElementalistPlayerController::Look);
}

void AElementalistPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();

	const FRotator YawRotation( 0.f, GetControlRotation().Yaw, 0.f );

	const FVector ForwardDirection = FRotationMatrix( YawRotation ).GetUnitAxis( EAxis::X );
	const FVector RightDirection = FRotationMatrix( YawRotation ).GetUnitAxis( EAxis::Y );

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput( ForwardDirection, InputAxisVector.X );
		ControlledPawn->AddMovementInput( RightDirection, InputAxisVector.Y );
	}
}

void AElementalistPlayerController::Look(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddControllerYawInput(InputAxisVector.X);
		ControlledPawn->AddControllerPitchInput(InputAxisVector.Y);
	}
}

