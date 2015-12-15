#include "colors.inc"
#include "textures.inc"
#include "stars.inc"
#include "xwing.inc"

//--------------------------------------------------------------------------
// camera ------------------------------------------------------------------
#declare Camera_0 = camera {
	angle 90  // front view
	location  <0.0 , 1.0 ,-10>
	right     x*image_width/image_height
	look_at   <0.0 , 0.0 , 0.0>
}
#declare Camera_1 = camera {
	angle 90  // diagonal view
	location  <3.0 , 2 ,-10>
	right     x*image_width/image_height
	look_at   <0.0 , 0.0 , 0.0>
}
#declare Camera_2 = camera {
	angle 90  // left side view
	location  <4.0 , -10.0 , 0.0>
	right     x*image_width/image_height
	look_at   <0.0 , 0.0 , 0.0>
}
#declare Camera_3 = camera {
	angle 90  // left side view
	location  <4.0, -10.0, 0.0>
	right     x*image_width/image_height
	look_at   <0.0 , 0.0 , 0.0>
	rotate 180*y
}
#declare Camera_4 = camera {
	angle 90  // back view
	location  <4.0, 0.0, 5.0>
	right     x*image_width/image_height
	look_at   <0.0 , 0.0 , 0.0>
}
#declare Camera_5 = camera {
	angle 90  // top view
	location  <0.0 , 13.0 ,-0.001>
	right     x*image_width/image_height
	look_at   <0.0 , 1.0 , 0.0>
}
#declare Camera_6 = camera {
	angle 90
	location <0.0, 2.0, -5.0> // cockpit
	right x*image_width/image_height
	look_at <0.0, 0.0, 0.0>
}
#declare Camera_7 = camera {
	angle 90
	location <6.0, 5.0, -8.0> // gun
	right x*image_width/image_height
	look_at <0.0, 0.0, 0.0>
}
#declare Camera_8 = camera {
	angle 90
	location <1.0, 2.0, -2.0> // engine
	right x*image_width/image_height
	look_at <0.0, 0.0, 0.0>
}
#declare Camera_9 = camera {
	fisheye
	angle 180
	location  <0.0 , 1.0 ,-9.0>
	right     x*image_width/image_height
	look_at   <0.0 , 0.0 , 0.0>
}

camera{Camera_7}

sphere {
   	<0,0,0>, 1
	texture {
		Starfield1 scale 0.25
	}
	scale 10000
}

light_source {
	<10,10,-1>
   	color White
	spotlight
	radius 12
	falloff 14
	tightness 10
	point_at <0,0,0>
}

object {XWing rotate 180*y}
