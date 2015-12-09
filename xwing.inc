#declare SquadronColour = color rgb <1, 0, 0>;

#declare xw_texture1 = texture {
	pigment {
		agate
		colour_map {
			[0 colour rgb 0.85]
			[0.5 colour rgb 0.95]
			[1.0 colour rgb 0.90]
		}
	}
	finish {ambient 0.2 diffuse 0.85}
	normal {dents 0.25 scale 0.25}
	scale 0.5
} texture {
	pigment {
		agate
		turbulence 0.3
		colour_map {
			[0.00 colour rgbf <0.05, 0.05, 0.05, 0.7>]
			[0.20 colour rgbt 1]
			[1.00 colour rgbt 1]
		}
	}
}

#declare xw_texture2 = texture {
	pigment {colour rgb 0.25}
	finish {ambient 0.2 diffuse 0.7 specular 0.9 roughness 0.01}
}

#declare xw_texture3 = texture {
	pigment {colour rgb <0.90, 0.91, 0.98>}
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
		colour_map {
			[0 colour rgb 0.65]
			[0.5 colour rgb 0.75]
			[1.0 colour rgb 0.70]
		}
	}
	finish {ambient 0.1 diffuse 0.7}
	normal {dents 1 scale 0.25}
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
		object {cylinder {<0,0,0>, <0,0,5.1>, 0.25} texture {xw_texture1}}
		object {cylinder {<0,0,5>, <0,0,8.5>, 0.15} texture {xw_texture1}}
		object {cylinder {<0,0,8.5>, <0,0,11>, 0.06} texture {xw_texture1}}
		object {cylinder {<0,0,8.3>, <0,0,8.5>, 0.2} texture {xw_texture1}}
		object {cylinder {<0,0,8.25>, <0,0,8.5>, 0.175} texture {xw_texture1}}
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

