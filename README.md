# CerebralFix Unreal Engine Coding Test #
## Instructions ##
We would like you to create a version of a Breakout-style game using the Unreal engine. We would like you to make this game in a 2.5D style - that is, using 3D assets for 2D gameplay. If you are unfamiliar with the game, there are many versions you can play for free online to get an idea of what we’re looking for. We do not expect you to spend a particularly long time on this - ideally no more than a few hours.

We like to use these tests as a conversation starter - something we can use to guide our interviews with you to understand how you write code. It isn’t a huge deal if you miss a requirement or don’t use the optimal approach in a situation; as long as you can speak to these decisions and explain your thinking during the interview, that’s fine. 

We also value creativity from every member of our teams, so we’d like to see you try to put your own spin on these classic mechanics. Finally, if any of these instructions aren’t clear or you have trouble getting the project set up, please feel free to reach out to us for help!

Note: Blueprints should be used sparingly - you should be using C++ for the vast majority of your logic.

## Functional Requirements ##
1. There should be a ball, a paddle, a number of bricks/other objects to hit, and some sort of barrier around the level
2. The ball should rebound off of the level barrier, the paddle, and the bricks
	a. Standard bricks should be affected by the ball in some way
3. The player should lose a life when the ball exits the bottom of the screen
	a. After losing a number of lives, the game should end
	b. The player’s lives should be shown in some manner (eg HUD element)
4. The game should restart and function correctly during subsequent playthroughs without needing to close and re-open the game
	a. This should either happen automatically after the game ends, or there should be a “Restart” button that the player can use to manually trigger this to happen
	b. There should be some sort of start state (eg a main menu) to show that the game has restarted

## What We’re Looking For ##
* Overall Process 
* Engine Familiarity
* Use of Object Oriented Design 
* Code Reusability
* Code Extensibility 
* Code Readability
* Version Control Use
* Creativity 

## Deliverables ##
* The source for your project hosted on bitbucket.org
* Instructions on how to play your game (including which version of Unreal you used to create it)
* You are welcome to include a packaged version of your game, although this is not a necessity. Either way, we do require access to the source code

## Technology ##
* You should use a recent version of Unreal - 4.22 or higher
* You are welcome to use third-party assets, as long as they do not include game logic code. If you do include any such assets, please provide a list of where you obtained these assets with your submission.

## Next Steps ##
1. [Fork](../../fork) this repository to your Bitbucket account, then clone it to your local machine
2. Create a new Unreal project in the repository
3. Make the game!
4. Once you are satisfied with your submission, ensure the developers included in the email you received about this test have access to the repository, and then reply to that email to let us know! We’ll get in touch once we’ve had a chance to review it.


