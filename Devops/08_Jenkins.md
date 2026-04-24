Jenkins
 it is open source automation tool/server, it automates repetitive tasks involved in building, testing and deploying the software

 CI -> Code push -> build -> testing -> reports

 CD -> code push ->build -> test ->artifact/package ->deploy to staging -> wait for approval ->deploy to prod

 -> write some code for some software -> push to github -> jenkin will automatically pulls the code when some changes happend on github ->
 compile the code -> unit/integration tests -> generate artifacts -> deploys artifacts/packages to server -> notify via email/slacks/teams -> run jobs on a cron schedule