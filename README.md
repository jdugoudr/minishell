# Minishell
This is a shell make for the 42 project scholl "minishell".
It's the first project of the 3 unix branch succession projects, wich make us produce a shell with very basic features (minishell project) to a almost complete one (42_sh project). Everything from scratch.

# Features
This minishell allow you to used all binaries files, using they absolute path or by reading the environment variable PATH. The execution of this commands are done in new processus called by fork.

It's also allow you to the use builtins comand echo, cd, env setenv and unsetenv.

You also can kill a child process by using Ctr-c.

# Limits
All of the builtins are relativelty simple and enable really basic syntax. (setenv VARIABLE VALUE, no '=' or "" manage).

Be aware that the program was only test on Mac-Os.

This shell don't allow you to use arrows keys to change your command line or help you by auto-completion with the tabulation key, this will come with the 2 others projects. So...
