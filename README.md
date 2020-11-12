# FreetimeStudio Triggers Plugin
A lightweight plugin to uniformly manage triggers for UE4. 

## Why?
Technically Unreal already has triggers, however they are nothing more than collision shapes that generate 
overlap events. This plugin provides dedicated trigger and listener actor components and an interface to 
expose them. 

Listeners can register to any number of triggers and get notified when a trigger fires the Trigger or Untrigger 
event. There are pre-implemented actors that contain the same functionality as Unreal's default triggers. 

Further more each trigger can implement filters that allow more fine control over what sort of objects can 
actually activate a trigger. The FtsPlayerTriggerFilter is provided to only allow player controlled pawns.

## How to use
### Trigger
Add an FtsTriggerComponent to an actor that should send trigger events. Implement the FtsTriggerInterface on 
the actor and override the GetTriggerComponent to return the component. 

To send events call Trigger or UnTrigger on the component. If you want to respect the filters call TryTrigger 
and TryUnTrigger instead.

### Listener
Add an FtsTriggerListenerComponent to an actor and call the AddTrigger(s) method to pass in obseverd triggers. 
Bind the component's OnTriggered and OnUnTriggered to listen to events.
