# CS-210

# Summarize the project and what problem it was solving.
This is a mock project designed to be a proof-of-concept for an RFID tracking program for a fictional company, Wildlife Zoo. The project is designed to take input from a file that lists animals associated with an RFID and populate it into a vector. When the code is run the user would load the file and may print the file to a readable table. The user may also add an animal with an associated RFID or delete one. The code also supports updating the input file with the animal(s) the user added to or removed from the vector.

# What did you do particularly well?
Error handling was coded very well in this project. Not only does the code check to ensure that numeric values fall within a certain range and that string lengths do not exceed a predefined length, it also checks if the type and subtypes supplied to an added record are currently supported by the code. This is also communicated back to the user so that they are aware.

# Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
One major way I would enhance my code is by splitting it up into multiple files that would contain the program’s several classes and functions. As this project was meant as a proof-of-concept design, I didn’t want to split it up into files until I knew I would be moving forward and creating more robust code for the final finished project for the client.

# Did you find writing any piece of this code challenging, and how did you overcome this? What tools and/or resources are you adding to your support network?
I found writing the AddAnimal() method the most difficult piece of code to write. Pointers have been a sticking point for me throughout this course and while I have made progress in understanding them, writing this method in the way that I wanted to write it required knowledge of how to use pointers well. I had to dive into tutorials on pointers and examples of them being used in classes on websites like Stack Overflow to resolve all of the errors in this method.

# What skills from this project will be particularly transferable to other projects and/or course work?
Honestly, the skills that were the most valuable to me throughout this project were my researching skills. I’m starting to understand that while having a good base knowledge of programming, syntax, and data structures is definitely needed to be a good programmer, so is your ability to find answers to very specific problems. Knowing how to research and knowing the right questions to ask is just as important as the knowledge itself. I believe I have significantly improved this skill while making this project.

# How did you make this program maintainable, readable, and adaptable?
I made this program maintainable by designing classes in a way that it’s easy to expand and create multiple other classes (i.e. animals). I made it readable by sticking to best practices when it came to naming conventions and having plenty of inline comments describing the logic. The program is also adaptable as there is not much code written in main(). The majority of the program is written into functions and classes making it very modular.
