# Table of content

* [Compilation](#compilation)
* [Usage](#usage)
* [More details](#more-details)

# Compilation

* Directory structure (after compiling)

```
├── CMakeLists.txt
├── README.md
├── callgraph.pdf
├── plan.pdf
├── reflection.pdf
├── lifegame.mp4
|
├── egypt-1.10
│   └── ...
├── includes
│   ├── graphic.h
│   ├── logic.h
│   ├── main.h
│   └── misc.h
├── out
│   ├── lifegame
│   ├── graphic
│   ├── logic
│   ├── misc
│   └── res
│       ├── arial.ttf
│       ├── final.txt
│       └── initial.txt
├── scripts
│   ├── build.sh
│   ├── egypt.sh
│   └── SDL.sh
├── src
│   ├── graphic.c
│   ├── logic.c
│   ├── main.c
│   └── misc.c
├── tests
│   ├── test_graphic.c
│   ├── test_logic.c
│   └── test_misc.c
└── unity
    └── ..
```

* Dependencies
  * [SDL](https://www.libsdl.org/)
  * [SDL_ttf](https://www.libsdl.org/projects/SDL_ttf/)
* Compiling dependencies 
  * ``gcc`` 
  * ``cmake`` 
  * ``make`` 
* Linux SDL installations (otherwise you need to compile them from source)

```bash
sudo apt-get install libsdl2-dev libsdl2-ttf-dev
```

* Compiling the program 

  * Using the script 

  ```bash
  cd scripts 
  chmod 755 build.sh
  ./build.sh
  ```

  * Compiling normally 

  ```bash
  mkdir build 
  cd build
  cmake ..
  make
  ```

  * Build properties 
    * Outputs are in ``out/`` folder 
    * The program itself is called ``lifegame`` 
    * ``misc``, ``logic``, ``graphic`` are all test programs 
    * ``res/``  directory must be in the same directory as ``lifegame`` 

# Usage

* Initial file configuration ``out/res/initial.txt`` 

  * File format 

  ```
  # row col rate pixels
  20 50 1 20
  ```

  * `row`: number of rows of cells
  * `col`: number of columns of cells
  * ``rate``: rate of simulation 
    * ``rate > 1`` simulation goes faster
    * ``rate < 1`` simulation goes slower
    * ``default = 1`` 
  * ``pixels`` : number of pixels per cell (``default = 20`` )
  * This file is only loaded at the beginning of the program 
  * Its favoured that (col * pixels > 750)   since the information bar has this length 

![image-20210329182123568](https://i.imgur.com/SJQbb7a.png)

* Final file configuration ``out/res/final.txt`` 

  * File format 

  ```
  # alive dead row col 
  12 38 5 10 
  0 	0 	0 	0 	0 	0 	0 	0 	0 	0 	
  0 	1 	0 	0 	0 	1 	1 	1 	0 	0 	
  0 	1 	1 	1 	1 	0 	0 	1 	1 	0 	
  0 	0 	0 	0 	0 	0 	0 	1 	1 	0 	
  0 	0 	0 	0 	0 	0 	0 	0 	0 	0 	
  ```

  * ``alive`` : number of alive cells
  * ``dead``: number of dead cells
  * ``row`` and ``col`` in ``final.txt`` must match ``row`` and ``col`` in ``initial.txt`` 
  * If they don't match the file will only file to load when it is requested 
  * The shape of the universe can be edited and loaded such that:
    * ``1``: is alive cell
    * ``0``: is dead cell
  * This file can be loaded (only in reset state) and outputted (at anytime) through the program

* Program properties 

  * Information bar 

    ![image-20210329181631416](https://i.imgur.com/BYlIM3P.png)

    * **Alive**: current ``alive`` 
    * **Dead**: current ``dead`` 
    * **Rate**: current ``rate`` 
    * **Zoom**: zoom of the grid 
    * **Cell**: Current cell coordinates ``[current_row][current_col]``  

  * Program states and shortcuts 

    * **All** state shortcuts (works at any state of the program)
      * ``r`` : resets everything and changes state to **start**
      * ``Left-mouse-click`` : assigns cells as alive 
      * ``Right-mouse-click`` : assigns cells as dead
      * ``s``: saves current grid configuration to ``final.txt`` 
      * ``Up-arrow-key``: speeds up the simulation (increases the rate)
      * ``Down-arrow-key``: slows down the simulation (decreases the rate)
      * ``Mouse-wheel-forward``: zooms in 
      * ``Mouse-wheel-backward``: zooms out
      * ``q``: resets zoom and speed of simulation (rate = 1, zoom = 100) 
    * **start** state shortcuts 
      * <u>Achieved when starting the program</u> 
      * <u>Achieved when pressing  `r`</u> 
      * ``Enter``: runs the simulation and changes state to **running**
      * ``o`` : 
        * resets the everything and loads the saved file ``final.txt``  
        * After that just press ``Enter`` to start the simulation 
    * **running** state 
      * <u>Achieved when pressing `Enter` while the program is in **start** state</u> 
      * <u>Achieved when pressing `space` while the program is in **paused** state</u>
      * ``space``: pauses the simulation and turns the state to **paused** 
    * **paused** state 
      * <u>This state is achieved when pressing ``space`` while the program is in **running** state</u>   
      * ``space``: runs the simulation again and changes the state to **running**
      * ``Right-arrow-key``: goes to next iteration of reshaping the grid 
      * ``Left-arrow-key``: goes to previous iteration of reshaping the grid

  * Other notes
    * You can only draw inside the white borders even when you zoom out
    * Any error will appear in the terminal where you ran the program in
    * max ``row`` is **500** and max ``col`` is **500** 

# More details

* [Demo](lifegame.mp4)
* [Call graph](callgraph.pdf)
* Git history 

```
commit ea90bd84718dbe4d3386dda96dd515290250c94c
Author: el20hzaa <el20hzaa@leeds.ac.uk>
Date:   Mon May 3 16:02:56 2021 +0300

    finished the reflection

commit a0a080c4774178a2d301fcb4fdd9fcb263ec80d4
Author: el20hzaa <el20hzaa@leeds.ac.uk>
Date:   Mon May 3 15:06:54 2021 +0300

    Fixing more files

commit 76aefd74ec95b466d650773cb5708f2cdcc2c461
Author: el20hzaa <el20hzaa@leeds.ac.uk>
Date:   Mon May 3 15:06:07 2021 +0300

    Adjusted the directory

commit cfaca4cd36539df254e99eb20540ca2a17dad184
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Tue Apr 6 19:09:38 2021 +0300

    Cleaned OUT directory and tested on linux and adjusted README

commit d4c8d43129f62360249ab3212528d50a451d8476
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Fri Apr 2 17:53:22 2021 +0300

    video trial-3 in README

commit 6843261913d27f30256b0146b15e552df8c2a1f8
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Fri Apr 2 17:49:26 2021 +0300

    video trial-2 in README

commit b18f737d8da63ec89048f5157a076d03fdd8aedb
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Fri Apr 2 17:47:24 2021 +0300

    video in README

commit d8855750b57d91d090575f18e6df00aedb1dccbf
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Fri Apr 2 17:40:40 2021 +0300

    added recording

commit 4b4fec2b989836d509c765767a09378a942eb14c
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Fri Apr 2 17:38:30 2021 +0300

    README

commit b4df932ae64d9d83a0ebac8bbf6aa4f06b8a3129
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Wed Mar 31 03:20:23 2021 +0300

    added call graph

commit 418fd1e536157792ad488eb6d6c0fa6b21dff28b
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Wed Mar 31 02:52:10 2021 +0300

    added more tests

commit 04e9bd3570e1da38daab440d0e901198832c58cd
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Tue Mar 30 16:16:10 2021 +0300

    finishing up the README file and will add more tests

commit f011cae29ce4fd395f1f3cf9b0a03051ecf5da2f
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Tue Mar 30 15:13:39 2021 +0300

    expanded undo functionality

commit abfdc63612241220d69ca22578a478156ab7f976
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Sun Mar 28 21:24:29 2021 +0300

    fixing more bugs in graphic.c

commit ce86577e2897cace7b3aa02f6a13aecf15535238
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Sun Mar 28 01:30:03 2021 +0300

    adjusted documentation in header files and added more comments

commit 64395d3aa37c4ae2547358631210769ad3d53272
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Sun Mar 28 00:17:04 2021 +0300

    fixed a bug in mouse drawing

commit 1320fa37c87adfd74dc52b5135cf68b053524cf7
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Sat Mar 27 22:25:01 2021 +0300

    adding more tests

commit 5ca081d74cbb331234f60ded8d17097f30b939cd
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Sat Mar 27 22:00:42 2021 +0300

    Finished misc.c and graphic.c

commit 8ee0fad18fe0867a4d983b87b309a412bdf7794f
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Sat Mar 27 20:12:54 2021 +0300

    Fixed 2 more bugs in screen size and zooming

commit dd2f3f48e8d2a728aa605eaa8dfb3a6729bb19cd
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Sat Mar 27 19:53:25 2021 +0300

    Fixed window size issue and zoom issue

commit 8075c180b7c4074cae0d9a96719f3871356c4c63
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Sat Mar 27 17:21:12 2021 +0300

    fixed a bug with mouse motion

commit 776c808562e07e7be7efa3926c61e692a2c53d1e
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Sat Mar 27 16:43:57 2021 +0300

    fixing more bugs

commit d16fd1d9ed3f50006c01e394ea5d09fb9b1f4fde
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Sat Mar 27 16:19:54 2021 +0300

    Fixed more bugs in graphic.c and misc.c

commit eebe54302bfa991107a7211531c976c4dccb738e
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Sat Mar 27 02:07:54 2021 +0300

    added more tests to misc.c

commit 1064261e5afe492ecf6515deaddc28ea119f2535
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Sat Mar 27 01:20:31 2021 +0300

    adding more features

commit 827e022b0dc32c37692aca809fdc84514c9bc0b1
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Fri Mar 26 23:17:00 2021 +0300

    fixed a bug in misc.c

commit 77edae6e668baab9b3e2ec945a0eac60c5245c70
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Fri Mar 26 22:09:42 2021 +0300

    testing misc.c

commit 13f372110df88e864f2706cfc426b4df1b35066f
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Fri Mar 26 21:49:02 2021 +0300

    Finishing graphic.c and misc.c

commit 22ac770374ac034f8c9220db0330a399dbaf0008
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Wed Mar 24 21:48:22 2021 +0200

    adjusted gitgnore to ignore build folders

commit 845008c4945239f3a93fced9d5e977637422ff2f
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Wed Mar 24 21:47:39 2021 +0200

    started with logic.c, test_logic.c

commit 585893f1068d3446f4ac00c45160f99a5ba161e2
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Tue Mar 23 20:22:16 2021 +0200

    Adjusted the directory structure more and started with logic.c and test_logic.c

commit 8734e5e6fb1d10f24039bd3f282c9efdda313c46
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Tue Mar 23 15:41:00 2021 +0200

    adjusted the directory and cmake list

commit 53afea7031920247c00d730514dea92bafa2e181
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Tue Mar 16 20:32:16 2021 +0200

    Adjusted main.h, CMakeList, and adjusted the directory structure

commit 0b43c0cd68cb5a1ed550780c1110a64c1fc28c09
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Sun Mar 14 15:48:24 2021 +0200

    fixed SDL.sh and build.sh

commit 60595c2f455224e96b1e9fc0649f806bcfbff150
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Sun Mar 14 15:38:12 2021 +0200

    Changed the directory structure and adjusted CMakeLists.txt and adjusted unity_tests

commit fa81270023233274fd887494d31a76a5575419ff
Author: Harith Al-Safi <el20hzaa@leeds.ac.uk>
Date:   Wed Mar 10 23:16:23 2021 +0200

    Adjusted the directory for cw2
```

* [repo](https://gitlab.com/comp1921_2021/el20hzaa/-/tree/master/coursework_2)

