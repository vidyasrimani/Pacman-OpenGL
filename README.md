# Pacman-OpenGL

Graphics is an extremely effective medium to communicate. This field has been growing rapidly over the years. Its applications are seen in various fields as humans can understand what is said diagrammatically better than what is given in terms of numbers and text. 

Pac-man is a classic arcade game that was released in 1980. It has been declared the arcade game with the highest video awareness. Even though it was released three decades ago, it is still played by many with the same enthusiasm.Its simplicity, ease of use and ability to keep the user hooked on to it for long has been responsible for this enormous popularity. In our project we have tried to recreate this game using OpenGL.

Our prime focus was interaction and animation. The application allows the user to control the movement of pac-man by using the keyboard. To mimic the animation presented to us in the original game, we made use of affine transformations. Using various transformations like rotate and translate to move the pac-man and monsters, we give the illusion of animation.

The layout of the board differs slightly from the original game. We have experimented with a 
different color scheme and rendered it with different lightings. Visually different from the 
inspiration, it still holds the essence of the game.

OVERVIEW
Arcade games have been a big part of any child’s childhood. Even as an adult, some people have a deep fondness for these games. One of these all-time favorite games is Pac-man, a classic arcade game that still lives on today, not in the form of an arcade game but on the internet as a flash game at least now.

Pac-man finds its origins in Japan, where is called Pakkuman. Developed in the 1980s, this game grew and found success as it found its way into the international market.  A developer, Namco made this game first released in Japan on May 22, 1980. To this day, Pac-man has not failed to entice its customers. It is a mind boggling and intensive game that keeps the gamer hooked to it till the very end.

In terms of revenue, Pac-Man has grossed over $2.5 billion, and this too by the 1990s. It has been declared the arcade game with the highest video awareness with over 94 percent of the massed knowing who or what Pac-Man is.

# OpenGL
OpenGL is a library for doing computer graphics. By using it, you can create interactive applications which render high-quality color images composed of 3D geometric objects and images.

OpenGL is window and operating system independent. As such, the part of your application which does rendering is platform independent. However, in order for OpenGL to be able to render, it needs a window to draw into. Generally, this is controlled by the windowing system on whatever platform one is working on.
	OpenGL is a software interface to graphics hardware. This interface consists of about 120 distinct commands, which you use to specify the objects and operations needed to produce interactive three-dimensional applications.

	OpenGL is designed to work efficiently even if the computer that displays the graphics you create isn’t the computer that runs your graphics program. This might be the case if you work in a networked computer environment where many computers are connected to one another by wires capable of carrying digital data. In this situation, the computer on programs can work across a network even if the client and server are different kinds of computers. If an OpenGL program isn’t running which your program runs and issues OpenGL drawing commands is called the client, and the computer that receives those commands and performs the drawing is called the server. The format for transmitting OpenGL commands (called the protocol) from the client to the server is always the same, so OpenGL across a network, then there’s only one computer, and it is both the client and the server.
	
OpenGL is designed as a streamlined, hardware-independent interface to be implemented on many different hardware platforms. To achieve these qualities, no commands for performing windowing tasks or obtaining user input are included in OpenGL; instead, you must work through whatever windowing system controls the particular hardware you’re using. Similarly, OpenGL doesn’t provide high-level commands for describing models of three-dimensional objects.

Such commands might allow you to specify relatively complicated shapes such as automobiles, parts of the body, airplanes, or molecules. With OpenGL, you must build up your desired model from a small set of geometric primitive-points, lines, and polygons.

# OpenGL COMMAND SYNTAX
As you might have observed from the simple program in the previous section, OpenGL commands use the prefix gl and initial capital letters for each word making up the command name (recall glClearColor(),for example.)Similarly, OpenGL defined constants begin with GL_use all capital letters, and use underscores to separate words (like GL_COLOR_BUFFER_BIT).

	You might also have noticed some seemingly extraneous letters appended to some command names (the 3f in glcolor3f(), for example).It’s true that the Color part of the command name is enough to define the command as one that sets the current color.
OpenGL-RELATED LIBRARIES
OpenGL provides a powerful but primitive set of rendering commands, and all higher-level drawing must be done in terms of these commands. Therefore, you might want to write your own library on top of OpenGL to simplify your programming tasks. Also, you might want to write some routines that allow an OpenGL program to work easily with your windowing system. In fact, several such libraries and routines have already been written to provide specialized features, as follows.
 
	The OpenGL Utility Library(GLU) contain several routines that use lower-level OpenGL commands to perform such tasks as setting up matrices for specific viewing orientations and projections, performing polygon tessellation, and rendering surfaces. This library is provided as part of your OpenGL implementation. It’s described in more detail in Appendix C and in the OpenGL Reference Manual. The more useful GLU routines are described in the chapters in this guide, where they’re relevant to the topic being discussed. GLU routines use the prefix glu.

	The OpenGL Extension to the X window system (GLX) provides a means of creating an OpenGL context and associating it with a drawable window on a machine that uses the X Window System. GLX is provided as an adjunct to OpenGL. GLX routines use the prefix glX.

	Open Inventor is an object-oriented toolkit based on OpenGL that provides objects and methods for creating interactive three-dimensional graphics applications. Available from Silicon Graphics and written in C++, Open Inventor provides pre-built objects and a built-in event model for user interaction, high-level application components for creating and editing three-dimensional scenes, and the ability to print objects and exchange data in other graphics formats.

# OpenGL AS A STATE MACHINE
OpenGL is a state machine. You put it into various states (or modes) that then remain in effect until you change them. As you’ve already seen, the current color is a state variable. You can set the current color to white, red, or any other color, and thereafter every object is drawn with that color until you set the current color to something else. The current color is only one of many state variables that OpenGL maintains. Others control such things as the current viewing and projection transformations, line and polygon stipple patterns, polygon drawing modes, pixel-packing conventions, positions and characteristics of lights, and material properties of the objects being drawn. Many state variables refer to modes that are enabled or disabled with the command glEnable() or glDisable().

	Each state variable or mode has a default value, and at any point you can query the system for each variable’s current value. Typically, you use one of the six following commands to do this:  glGetBooleanv(), glGetDoublev(), glGetFloatv(), glGetIntegerv(), glGetPointerv(), or glIsEnabled().
	
 Some state variables have a more specific query command (such as glGetLight*() ,
glGetError(), or glGetPolygonStipple()). In addition, you can save a collection of state variables on an attribute stack with glPushAttrib() or glPushClientAttrib(), temporarily modify them, and later restore  the values with glPopAttrib() or glPopClientAttrib().

The picture below is that of the Pac-Man, the protagonist of the arcade game we will simulate.
https://cloud.githubusercontent.com/assets/8260656/11317931/638983da-9065-11e5-936c-3da0368786ca.png

					Fig 2.1 Pac-man
The white dot next to the Pac-man are called pebbles. Each pebble eaten by the Pac-man is equivalent to one point gained.
https://cloud.githubusercontent.com/assets/8260656/11317932/63908428-9065-11e5-9394-a9387fa05019.png
The above four figures are called ghosts in the arcade game. These ghosts chase the Pac-Man throughout the grid. When it makes contact, the Pac-Man is destroyed and has to restart the game after losing a life. Once all the lives are exhausted, the game is over.

The ghosts can be rendered useless when the Pac-Man consumes a giant pebble. This turns the ghost blue and when consumed by the Pac-Man goes to its original place and starts again.
The blue Pac-Man looks like the picture shown below.
https://cloud.githubusercontent.com/assets/8260656/11317934/63925ae6-9065-11e5-9a52-c553a183171a.png

The actual Pac-Man game looks like the following picture:
https://cloud.githubusercontent.com/assets/8260656/11317933/63922274-9065-11e5-9eea-f4ba7719d127.png
