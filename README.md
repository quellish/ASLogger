
###Common Usage

Replace `NSLog()` across most of your codebase with `DebugLog()`. You can do this in Xcode per-file or project wide.

To do so in Xcode 6:

![Xcode 6 Find and Replace](images/Replace1.png)

You can insert patterns using the key shortcut Control-Option-Command-P:
![Xcode 6 Insert Patterns](images/InsertPatterns.png)

###Using Log Levels

Example of EmergencyLog:

    EmergencyLog(@"The system is going down now!");

Example of CriticalLog:

    CriticalLog(@"#TheSituation is Critical!");

Example of ErrorLog:

    ErrorLog(@"Encountered an error: %@", error);

Example of WarningLog:

    WarningLog(@"You are almost out of disk space.")

Example of NoticeLog:

	NoticeLog();

Example of InfoLog:

	InfoLog();

Example of DebugLog:

	DebugLog();


Apple best practices for logging are documented in the [Daemons and Services Programming Guide](https://developer.apple.com/library/mac/documentation/MacOSX/Conceptual/BPSystemStartup/Chapters/LoggingErrorsAndWarnings.html)