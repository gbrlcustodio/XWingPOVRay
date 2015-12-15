#declare SquadronColour = color rgb <1, 0, 0>;

#declare destak = texture {
  pigment {color Red}
}

#declare xw_texture1 = texture {
  pigment {
    bozo
    color_map {
      [0 color rgb 0.85]
      [0.5 color rgb 0.95]
      [1.0 color rgb 0.90]
    }
  }
  finish {ambient 0.2 diffuse 0.7}
  normal {dents 0.25 scale 0.25}
  scale 0.5
}

#declare xw_texture2 = texture {
  pigment {color rgb 0.25}
  finish {ambient 0.2 diffuse 0.7 specular 0.9 roughness 0.01}
}

#declare xw_texture3 = texture {
  pigment {color rgb <0.90, 0.91, 0.98>}
  finish {
	metallic
	ambient 0.2
	diffuse 0.7
	brilliance 6
	reflection 0.25
	phong 0.75
	phong_size 80
  }
}

#declare xw_texture4 = texture {
  pigment {
	bozo
	color_map {
	  [0 color rgb 0.65]
	  [0.5 color rgb 0.75]
	  [1.0 color rgb 0.70]
	}
  }
  finish {ambient 0.1 diffuse 0.7}
  normal {dents 1 scale 0.25}
  scale 0.5
}

#declare xw_texture5 = texture {
  pigment {
	agate
	color_map {
	  [0 color rgb 0.85]
	  [0.5 color rgb Orange]
	  [1 color OrangeRed]
	}
  }
  finish {ambient 0.2 diffuse 0.85}
  normal {dents 0.25 scale 0.25}
  scale 0.5
}

#declare gun = object {
  union {
	object {cylinder {<0,0,-4>, <0,0,0>, 0.45} texture {xw_texture1}}
	object {cylinder {<0,0,-0.3>, <0,0,0>, 0.5} texture {xw_texture1}}
	object {cylinder {<0,0,-3.5> <0,0,-0.7>, 0.5} texture {xw_texture1}}
	object {cylinder {<0,0,-3.55> <0,0,-0.7>, 0.5} texture {xw_texture1}}
	object {torus {0.45, 0.05} rotate 90*x translate <0,0,-3.5> texture {xw_texture4}}
	object {cylinder {<0,0,-4.6>, <0,0,-4>, 0.25} texture {xw_texture4}}
	object {cylinder {<0,0,-4.7>, <0,0,-4.5>, 0.35} texture {xw_texture1}}
	object {torus {0.3, 0.05} rotate 90*x translate <0,0,-4.7> texture {xw_texture1}}
	object {torus {0.3, 0.05} rotate 90*x translate <0,0,-4.5> texture {xw_texture1}}
	object {
	  intersection {
		object {box {<0,-0.25,-3>, <1, 0.25, -1.5>}}
		object {cylinder {<0,0,-4>, <0,0,0>, 0.55}}
	  }
	  texture {xw_texture1}
	}

	object {box {<0,-0.1,-3>, <0.6,0.1,-2>} texture {xw_texture1}}
	object {box {<0,-0.1,-3>, <0.55,-0.08,0>} texture {xw_texture1}}
	object {box {<0,0.08,-3>, <0.55,0.1,0>} texture {xw_texture1}}
	object {
	  difference {
		object {cylinder {<0,0,0.2>, <0,0,0.5>, 0.525}}
		object {cylinder {<0,0,0>, <0,0,1>, 0.475}}
	  }
	  texture {xw_texture1}
	}
	object {
	  union {
		#declare _count = 0;
		#while(_count < 360)
		  object {box {<-0.02,0,0>, <0.02, 0.475, 0.5>} rotate <0,0,_count>}
		  #declare _count = _count + 30;
		#end
	  } texture {xw_texture3}
	}
	object {cylinder {<0,0,0>, <0,0,4.1>, 0.25} texture {xw_texture1}}
	object {cylinder {<0,0,4.1>, <0,0,5.1>, 0.25} texture {xw_texture5}}
	object {cylinder {<0,0,5>, <0,0,8.5>, 0.15} texture {xw_texture1}}
	object {cylinder {<0,0,8.5>, <0,0,11>, 0.06} texture {xw_texture1}}
	object {cylinder {<0,0,8.3>, <0,0,8.5>, 0.2} texture {xw_texture1}}
	object {cone {<0,0,8.25>, 0.3, <0,0,8.5> 0.2} texture {xw_texture1}}
	object {
	  difference {
		object {cylinder {<-0.1,0,9>, <0.1, 0, 9>, 0.5} texture {xw_texture1}}
		object {cylinder {<-1,0,9>, <1,0,9>, 0.425}}
		object {plane {<0,0,-1>, -9}}
	  }
	  texture {xw_texture1}
	}
  }
}

#declare wing_top_surface = object {
  intersection {
	object {box {<0,0.1,-6>, <14,0.15,0>}}
	object {
	  union {
		object {cylinder {<0,0,0>, <4.5,0,0>, 5}}
		object {cone {<4.5,0,0>, 5.5, <13.5,0,0>, 5}}
	  }
	}
  }
  texture {
	material_map {
	  gif "images/wing_top_detail.gif"
	  map_type 0
	  texture {xw_texture1}
	  texture {xw_texture1 pigment {color SquadronColour} finish {ambient 0.3}}
	}
	rotate x*90
	translate <0,0,-1>
	scale 13.5
  }
}

#declare wing_bottom_surface = object {
  intersection {
	object {box {<0,0,-6>, <14,0.1,0>}}
	object {
	  union {
		object {cylinder {<0,0,0>, <4.5,0,0>, 5}}
		object {cone {<4.5,0,0>, 5.5, <13.5,0,0>, 4}}
	  }
	  scale <1,100,1>
	}
  }
  texture {
	material_map {
	  gif "images/wing_bottom_detail.gif"
	  map_type 0
	  texture {xw_texture1}
	  texture {xw_texture1 pigment {color rgb 0.05}}
	}
	rotate x*90
	translate <0,0-1>
	scale 13.5
  }
}

#declare wing_detail = object {
  union {
	object {
	  intersection {
		object {
		  difference {
			object {box {<2.5,0.01,-4.5>, <6.5,1,0.05>}}
			object {box {<0,0,-7>, <5,5,1>} rotate <0,0,-15> translate <4.75,1,0>}
		  }
		}
		object {
		  union {
			object {cylinder {<0,0,0>, <4.5,0,0>, 5}}
			object {cone {<4.5,0,0>, 5.5, <13.5,0,0>, 4}}
		  }
		  scale <1,100,1>
		}
		object {cylinder {<3.5,1.15,1>, <3.5,1.15,-6>, 0.9} inverse}
	  }
	}
	object {box {<6,0.1,-3>, <7,0.25,-1>}}
	object {box {<12.9,0.1,-4>, <13.1,0.6,-1>}}
	object {box {<8,0.1,-0.5>, <9,0.16,-1.2>}}
	object {box {<8,0.1,-1.3>, <9,0.16,-2>}}
	object {box {<8,0.1,-4>, <8.4,0.16,-3>}}
	// detalhes frontais do bloco do motor
	object {
	  difference {
		object {
		  union {
			object {box {<3.5,0.1,0.05>, <6.3,0.5,0.1>}}
			object {box {<5.5,0.15,0.05>, <5.8,0.45,0.15>}}
			object {cylinder {<4.5,0.3,0.05>, <4.5,0.30,0.10>, 0.15}}
			object {cylinder {<4.5,0.3,0.10>, <3.5,1.15,0.10>, 0.05}}
			object {
			  intersection {
				object {box {<3.5,0.1,0.05>, <5.5,0.9,0.1>}}
				object {cone {<4,0.1,0.1>, 1, <5.5,0.1,0.1>, 0} scale <1,1,100>}
			  }
			}
		  }
		}
		object {cylinder {<3.5,1.15,1>, <3.5,1.15,-1>, 0.9}}
	  }
	}
  }
  texture {xw_texture1}
}

#declare engine_front = object {
  union {
	object {cylinder {-3.6*z, -4.5*z, 1.1}}
	object {
	  difference {
		object {cylinder {0*x, -4*z, 1}}
		object {cylinder {0.1*z, -2*z, 0.9}}
		object {box {<-2,0,-0.1>, <2,2,2>}}
	  }
	}
	object {
	  intersection {
		object {box {<-1.1,-0.05,-2>, <1.1,0.05,0>}}
		object {cylinder {-2.1*z, 0.1*z, 1}}
	  }
	}
	object {cylinder {-3*z, 0*z, 0.15}}
	object {cylinder {-3*z, -0.15*z, 0.2}}
	object {cylinder {-3*z, -0.3*z, 0.25}}
	object {cylinder {-3*z, -0.45*z, 0.3}}
	object {
	  intersection {
		object {plane {-y, 0} translate 0.05*y}
		object {cylinder {-4*z, z, 1} inverse}
		object {
		  union {
			object {cylinder {-0.3*z, -0.8*z, 1.075}}
			object {cylinder {-0.8*z, -4*z, 1.05}}
		  }
		}
	  }
	}
	object {cone {z, 0, -1.5*z, 1} pigment {color rgb 0.05}}
  }
  texture {xw_texture1}
}

#declare engine_ring = object {torus {0.7, 0.01} rotate <90,0,0>}

#declare engine_one = object {
  difference {
	object {
	  union {
		object {sphere {<0,0,0>, 0.7} scale <1,1,0.5>}
		object {sphere {<0,0,0>, 0.25} scale <1,1,3>}
		object {cylinder {<0,0,-4>, <0,0,0>, 0.7}}
		object {torus {0.7, 0.1} rotate 90*x scale <1,1,10> translate <0,0,-3>}
		object {engine_ring translate -1*z}
		#declare index = 0.3;
		#while(index <= 0.6)
		  object {engine_ring translate -(1 + index)*z}
		  #declare index = index + 0.1;
		#end
		object {cylinder {<0,0,-3.6>, <0,0,-3.8>, 0.8}}
		object {cylinder {<0,0,-3.85>, <0,0,-4.15>, 0.8}}
	  }
	}
	object {cylinder {<0,0,-2>, <0,0,-5>, 0.5}}
  }
  texture {xw_texture1}
}

#declare engine_two = object {
  union {
	object {cone {<0,0,0>, 0.78, -1*z, 0.68}}
	object {
	  intersection {
		object {cone {<0,0,0>, 0.8, -1*z, 0.72}}
		object {
		  union {
			#declare index = 0;
			#while(index < 360)
			  object {box {<-0.05,0,-1.1>, <0.05,1,0.1>} rotate index*z}
			  #declare index = index + 15;
			#end
		  }
		}
	  }
	}
  }
  texture {xw_texture1}
}

#declare engine_three = object {
  union {
	object {
	  difference {
		object {engine_two}
		object {
		  cylinder {0.1*z, -2*z, 0.65}
		  texture {
			/*sombras negras dentro do exaustor e cinza no final*/
			pigment {
			  gradient z
			  color_map {
				[0 color rgb 0]
				[1 color rgb 0.85]
			  }
			  scale 1
			}
		  }
		}
	  }
	  texture {xw_texture1}
	}
	object {
	  intersection {
		object {cylinder {0*x, -z, 0.63}}
		object {
		  union {
			#declare index = 0;
			#while(index < 360)
			  object {box {<-0.05,0,-0.4>, <0.05,1,0>} rotate index*z}
			  #declare index = index + 30;
			#end
		  }
		}
	  }
	  texture {xw_texture3 pigment {color rgb 0.3}}
	}
	object {sphere {0*x, 0.2} scale<1,1,2> translate -0.4*z texture {xw_texture3}}
	light_source{
		0
		rgb<1,0,0>
		translate z*1.5
	}
	light_source{
		0
		rgb<1,1,0>
		translate z*0.5
	}
  }
}

#declare engine_back = object {
  union {
	object {engine_one}
	object {engine_three translate -4.2*z}
  }
  texture {xw_texture1}
}

#declare engine = object {
  union {
	object {engine_front}
	object {engine_back translate <0,0.7,-4.75>}
  }
  texture {xw_texture1}
}

#declare wing = object {
  union {
	object {wing_top_surface}
	object {wing_bottom_surface}
	object {wing_detail}
	object {gun translate <13, 0.8, 0>}
	object {engine translate <3.5, 1.15, 1>}
  }
}

#declare body_rearA = object {
  intersection {
	object {box {<-2,-2.5,-6.5>, <2,2,4>}}
	object {
	  union {
		object {cone {0*y, 2, 1.501*y, 1.75}}
		object {cone {1.5*y, 1.751, 2.01*y, 1}}
		object {cone {0.01*y, 2, -2.01*y, 1.5}}
		object {cone {-2*y, 1.5, -2.5*y, 0}}
	  }
	  scale <1,1,1000>
	}
  }
}

#declare body_rearB = object {
  difference {
	object {body_rearA}
	object {box {<-3,-0.5,-5>, <3,0.5,0>}}
	object {cylinder {<0,1,2>, <0,3,2>, 0.55}}
	object {box {<-0.75,1.8,-6.5>, <0.75,2.1,1>}}
	object {plane {-y, 0} rotate -25*x translate <0,1.6,-6.5>}
	object {plane {y, 0} rotate -16.699*x translate <0,-2.5,-1>}
	object {box {<-4,0,2>, <4,4,6>}}
	object {
	  difference {
		object {body_rearA}
		object {box {<-4,-4,-7>, <4,1.5,-6>}}
	  }
	  translate -0.01*z
	  scale <0.95,0.95,1>
	}
  }
  texture {xw_texture1}
}

#declare back_hatch = object {
  union {
	object {
	  intersection {
		object {body_rearA}
		object {
		  union {
			object {box {<-4,-4,-6.1>, <4,1.5,-6>}}
			object {cylinder {<-2,-1,-6.1>, <0,0,-6.1>, 0.05} translate <0,0,0> scale <1,1,1>}
			object {cylinder {<-2,-1,-6.1>, <0,0,-6.1>, 0.05} translate <0,0.5,0> scale <1,1,1>}
			object {cylinder {<-2,-1,-6.1>, <0,0,-6.1>, 0.05} translate <0,1,0> scale <1,1,1>}
			object {cylinder {<-2,-1,-6.1>, <0,0,-6.1>, 0.05} translate <0,1.5,0> scale <1,1,1>}
			object {cylinder {<-2,-1,-6.1>, <0,0,-6.1>, 0.05} translate <0,0,0> scale <-1,1,1>}
			object {cylinder {<-2,-1,-6.1>, <0,0,-6.1>, 0.05} translate <0,0.5,0> scale <-1,1,1>}
			object {cylinder {<-2,-1,-6.1>, <0,0,-6.1>, 0.05} translate <0,1,0> scale <-1,1,1>}
			object {cylinder {<-2,-1,-6.1>, <0,0,-6.1>, 0.05} translate <0,1.5,0> scale <-1,1,1>}
		  }
		}
	  }
	  texture {xw_texture1}
	}
	object {box {<-1,-1.5,-6.25>, <1,1.5,-6.1>} texture {xw_texture1}}
	object {cylinder {<0,0,-6.3>, <0,0,-6.2>, 0.6} texture {xw_texture1}}
	object {
	  difference {
		object {cylinder {<0,0,-6.3>, <0,0,-6.2>, 0.8}}
		object {cone {<0,0,-6.301>, 0.8, <0,0,-6.2>, 0.7}}
	  }
	  texture {xw_texture1}
	}
	object {cylinder {<-1,-1.75,-6.1>, <-0.75,-1.75,-6.1>, 0.2} scale <1,1,1> texture {xw_texture1}}
	object {cylinder {<-1,-1.75,-6.1>, <-0.75,-1.75,-6.1>, 0.2} scale <-1,1,1> texture {xw_texture1}}
	object {cylinder {<-1,-1.75,-6.1>, <1,-1.75,-6.1>, 0.1} texture {xw_texture1 pigment {colour rgb 0.55}}}

  }
  scale <0.95,0.95,1>
}

#declare AA = <-2.00, 0, 4>;
#declare AB = <2.00, 0, 4>;
#declare AC = <-1.75, -1, 4>;
#declare AD = <1.75, -1, 4>;
#declare AE = <-1, 0, 17>;
#declare AF = <1, 0, 17>;
#declare AG = <-0.75, -0.5, 17>;
#declare AH = <0.75, -0.5, 17>;

#declare nose_under_side = object {
  mesh {
    triangle {AA,AG,AC}
    triangle {AA,AG,AE}
    triangle {AC,AG,AD}
    triangle {AH,AG,AD}
    triangle {AB,AD,AH}
    triangle {AB,AF,AH}
    triangle {AA,AE,AB}
    triangle {AF,AE,AB}
  }
  texture {xw_texture1}
}

#declare BA = <-0.9, 2.0, 3.0>;
#declare BB = <0.9, 2.0, 3.0>;
#declare BC = <-0.9, 2.3, 3.4>;
#declare BD = <0.9, 2.3, 3.4>;
#declare BE = <-1.4, 1.2, 4.5>;
#declare BF = <1.4, 1.2, 4.5>;
#declare BG = <-1.0, 2.3, 4.5>;
#declare BH = <1.0, 2.3, 4.5>;
#declare BI = <-0.75, 1.5, 9.0>;
#declare BJ = <0.75, 1.5, 9.0>;
// Os ponto a seguir estão dentro do cokpit
#declare BK = <-1.3, 0.2, 4.5>;
#declare BL = <1.3, 0.2, 4.5>;
#declare BM = <-0.5, 0.5, 8.0>;
#declare BN = <0.5, 0.5, 8.0>;

#declare CA= <-2, 0, 2>;
#declare CB= <2, 0, 2>;
#declare CC= <-1.75, 1.5, 2>;
#declare CD= <1.75, 1.5, 2>;
#declare CE= <-1, 2, 2>;
#declare CF= <1, 2, 2>;

#declare FR = 0.05;
#declare screen = object {
  union {
    object {
      mesh {
        triangle {BA,BE,BC}
        triangle {BF,BD,BB}
        triangle {BE,BC,BG}
        triangle {BF,BD,BH}
        triangle {BA,BB,BD}
        triangle {BA,BC,BD}
        triangle {BE,BG,BI}
        triangle {BF,BH,BJ}
        triangle {BG,BI,BJ}
        triangle {BG,BH,BJ}
      }
      texture {
        pigment {color rgbf <0.75, 0.75, 0.8, 0.7>}
        finish {specular 0.7 roughness 0.01}
      }
    }
    object {
      union {
        object {cylinder {BA,BB,FR}}
        object {cylinder {BC,BD,FR}}
        object {cylinder {BC,BG,FR}}
        object {cylinder {BG,BH,FR}}
        object {cylinder {BI,BJ,FR}}
        object {cylinder {BA,BE,FR}}
        object {cylinder {BB,BF,FR}}
        object {cylinder {BA,BC,FR}}
        object {cylinder {BB,BD,FR}}
        object {cylinder {BC,BG,FR}}
        object {cylinder {BD,BH,FR}}
        object {cylinder {BE,BG,FR}}
        object {cylinder {BF,BH,FR}}
        object {cylinder {BE,BI,FR}}
        object {cylinder {BF,BJ,FR}}
        object {cylinder {BG,BI,FR}}
        object {cylinder {BH,BJ,FR}}

      }
      texture {xw_texture1}
    }
    object {
      union {
        object {sphere {BA,FR}}
        object {sphere {BB,FR}}
        object {sphere {BC,FR}}
        object {sphere {BD,FR}}
        object {sphere {BE,FR}}
        object {sphere {BF,FR}}
        object {sphere {BG,FR}}
        object {sphere {BH,FR}}
        object {sphere {BI,FR}}
        object {sphere {BJ,FR}}
      }
      texture {xw_texture1}
    }
  }
  texture {xw_texture1}
}
#declare DA=<-2,0,3.5>;
#declare DB=<2,0,3.5>;
#declare DC=<-1.9,0.9,3.5>;
#declare DD=<1.9,0.9,3.5>;
#declare DE=<-0.75,0,18>;
#declare DF=<0.75,0,18>;
#declare DG=<-0.55,0.9,18>;
#declare DH=<0.55,0.9,18>;

#declare cockpit = object {
  mesh {
    triangle {BB,BF,BE}
    triangle {BB,BA,BE}

    triangle {BF, BE, BL}
    triangle {BK, BE, BL}

    triangle {BF,BL,BN}
    triangle {BF,BJ,BN}

    triangle {BL,BK,BN}
    triangle {BM, BK, BN}

    triangle {BJ,BN,BM}
    triangle {BJ,BI,BM}

    triangle {BE,BK,BM}
    triangle {BE,BI,BM}
  }
  texture {xw_texture1 pigment {color rgb 0.55}}
}

#declare screen_surround = object {
  union {
    object {
      mesh {
        triangle {BE,CA,CC}
        triangle {BF,CB,CD}
        triangle {BA,CC,CE}
        triangle {BB,CD,CF}
        triangle {BA,CC,BE}
        triangle {BB,CD,BF}

        triangle {BB,CF,CE}
        triangle {BB,BA,CE}

        triangle {BD,BC,BH}
        triangle {BG,BC,BH}

        triangle {DC, CA, BE}
        triangle {DD, CB, BF}

        triangle {DA, DC, CA}
        triangle {DB, DD, CB}

        triangle {DC, BE, DG}
        triangle {DD, BF, DH}

        triangle {BE, BI, DG}
        triangle {BF, BJ, DH}

        triangle {BI, DG, DH}
        triangle {BI, BJ, DH}
      }
      texture {xw_texture1}
    }
    object {
      mesh {
        triangle {DA,DC,DE}
        triangle {DB,DD,DF}
        triangle {DG,DC,DE}
        triangle {DH,DD,DF}
      }
      texture {xw_texture1 pigment {colour SquadronColour}}
    }
  }
  texture {xw_texture1}
}

#declare nose_tip = object {
  intersection {
    object {sphere {<0,-4,18>, 5}}
    object {sphere {<0,12,17>, 12.6}}
    object {sphere {<0,0,0>, 1} scale <10,0.9,1> translate <0,1,17> inverse}
    object {box {<-2, -2, 17>, <2, 2, 25>}}
    object {box {<-0.25, 0.65, 19>, <0.25, 5, 25>} inverse}
    object {
      union {
        object {cone {<0,0,0>, 1.15, <0,2,0>, 0.25}}
        object {cone {<0,0,0>, 1.15, <0,-0.6,0>, 0.85}}
      }
      scale <1,1,2.75>
      translate <0,0,18>
    }
  }
  texture {xw_texture1}
}

#ifndef (WingRotation)
	#declare WingRotation = 20;
#end

#declare XWing = object {
  union {
    object {body_rearB}
    object {back_hatch}
    object {nose_under_side}
    object {nose_tip}
    object {screen}
    object {screen_surround}
    object {cockpit}
    object {wing rotate <0,0,WingRotation> translate <0,0.1,0> scale <1,1,1>}
    object {wing rotate <0,0,WingRotation> translate <0,0.1,0> scale <-1,1,1>}
    object {wing rotate <0,0,WingRotation> translate <0,0.1,0> scale <1,-1,1>}
    object {wing rotate <0,0,WingRotation> translate <0,0.1,0> scale <-1,-1,1>}
  }
  scale 0.4
  texture {xw_texture1}
}
