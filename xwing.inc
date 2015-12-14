#declare SquadronColour = color rgb <1, 0, 0>;

#declare destak = texture {
	pigment {color Red}
}

#declare xw_texture1 = texture {
	pigment {
		agate
		color_map {
			[0 color rgb 0.85]
			[0.5 color rgb 0.95]
			[1.0 color rgb 0.90]
		}
	}
	finish {ambient 0.2 diffuse 0.85}
	normal {dents 0.25 scale 0.25}
	scale 0.5
} texture {
pigment {
	agate
	turbulence 0.3
	color_map {
		[0.00 color rgbf <0.05, 0.05, 0.05, 0.7>]
		[0.20 color rgbt 1]
		[1.00 color rgbt 1]
	}
}
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
		/* object {cylinder {<0,0,8.25>, <0,0,8.5>, 0.3} texture {xw_texture1}} */
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
      scale <1,100,1>
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
    object {cylinder {<0,0,-3.6>, <0,0,-4.5>, 1.1}}
    object {
      difference {
        object {cylinder {<0,0,0>, <0,0,-4>, 1}}
        object {cylinder {<0,0,0.1>, <0,0,-2>, 0.9}}
        object {box {<-2,0,-0.1>, <2,2,2>}}
      }
    }
    object {
      intersection {
        object {box {<-1.1,-0.05,-2>, <1.1,0.05,0>}}
        object {cylinder {<0,0,-2.1>, <0,0,0.1>, 1}}
      }
    }
    object {cylinder {<0,0,-3>, <0,0,0>, 0.15}}
    object {cylinder {<0,0,-3>, <0,0,-0.15>, 0.2}}
    object {cylinder {<0,0,-3>, <0,0,-0.3>, 0.25}}
    object {cylinder {<0,0,-3>, <0,0,-0.45>, 0.3}}
    object {
      intersection {
        object {plane {-y, 0} translate <0,0.5,0>}
        object {cylinder {<0,0,-4>, <0,0,1>, 1} inverse}
        object {
          union {
            object {cylinder {<0,0,-0.3>, <0,0,-0.8>, 1.075}}
            object {cylinder {<0,0,-0.8>, <0,0,-4> 1.05}}
          }
        }
      }
    }
    object {cone {<0,0,-1>, 0, <0,0,-1.5>, 1} pigment {color rgb 0.05}}
    /* object { */
    /*   intersection { */
    /*     object { */
    /*       difference { */
    /*         object {cylinder {<0,0,-4>, <0,0,0>, 1.075} pigment {color Green}} */
    /*         object {cylinder {<0,0,-4.1>, <0,0,0.1>, 0.9}} */
    /*       } */
    /*     } */
    /*     object { */
    /*       union { */
    /*         object {box {<-2, -0.5, -2.3>, <0, 0.3, -1.5>} rotate <0,0,-45> scale <1,1,1>} */
    /*         object {box {<-2, -0.5, -2.3>, <0, 0.3, -1.5>} rotate <0,0,-45> scale <-1,1,1>} */
    /*         object {box {<-2, -0.5, -3.3>, <0, 0.3, -2.5>} rotate <0,0,-45> scale <1,1,1>} */
    /*         object {box {<-2, -0.5, -3.3>, <0, 0.3, -2.5>} rotate <0,0,-45> scale <-1,1,1>} */
    /*         object {box {<-0.4, 0, -2>, <0.4, 2, -0.5>}} */
    /*         object {box {<-0.2, 0, -4>, <0.2, 2, -2>}} */
    /*       } */
    /*     } */
    /*   } */
    /* } */
    /* object { */
    /*   intersection { */
    /*     object { */
    /*       union { */
    /*         object { */
    /*           difference { */
    /*             object {cylinder {<0,0,-1>, <0,0,-1.3>, 1.075}} */
    /*             object {cylinder {<0,0,-0.9>, <0,0,-1.4>, 1}} */
    /*           } */
    /*         } */
    /*         #declare Count = 0; */
    /*         #while (Count < 360) */
    /*           object {cylinder {<0,1.075, -1>, <0, 1.075, -1.3>, 0.02} rotate <0,0,Count>} */
    /*           #declare Count=Count+2; */
    /*         #end */
    /*       } */
    /*     } */
    /*     object {plane {<0,-1,0>, 0}} */
    /*   } */
    /* } */
  }
  texture {xw_texture1}
}

#declare engine_ring = object {torus {0.7, 0.01} rotate <90,0,0>}

#declare wing = object {
  union {
    object {wing_top_surface}
    object {wing_bottom_surface}
    object {wing_detail}
    object {gun translate <13, 0.8, 0>}
    /* object {engine translate <3.5, 1.15, 1>} */
  }
}
