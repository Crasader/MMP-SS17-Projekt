# MMP-SS17-Projekt 
# How to build

Install Cocos Framework: cocos2d-x-3.15.1
Install VS Studio Community Edition

Runtime error with "HsSrv.dll": Uninstall every Asus Audio Driver

Build error with "Msvcr100.dll": Install 32-bit version of https://www.microsoft.com/en-us/download/details.aspx?id=30679

Some other dll runtime error: Install 32-bit version of https://www.microsoft.com/de-de/download/details.aspx?id=48145

Build error with "The command if not exists ..." or "cannot open file 'libcurl.lib'": Create a new Cocos Project with "cocos new MMP-SS17-Projekt -l cpp". 
Do everything you need to do to compile this new (HelloWorld)Project. Then Copy all Classes and everything from the res folder into the newly created Cocos Project 
(overwrite AppDelegate.cpp and .h). Make sure alls cpp and h files are imported into the Visual Studio Project -> compile project.
