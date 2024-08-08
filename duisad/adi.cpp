void AYourCharacterClass::CancelActiveTasks()
{
    if (FollowCursorAbilityTask && FollowCursorAbilityTask->IsActive())
    {
        FollowCursorAbilityTask->EndTask();
    }
    
    if (MoveCharacterToCursorAbilityTask && MoveCharacterToCursorAbilityTask->IsActive())
    {
        MoveCharacterToCursorAbilityTask->EndTask();
    }
}
