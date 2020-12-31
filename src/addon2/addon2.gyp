{
    "targets":[
        {
            "target_name":"addon2",
            'include_dirs': [ './','../include',"<!@(node -p \"require('node-addon-api').include\")"],
            "sources":[ 
                        "dog.cc"
            ],
            "defines":['NDEBUG','USE_NAPI'],
            "cflags_cc!":['-fno-rtti'],
            "cflags_cc":['-fexceptions','-std=c++14'],
			"cflags":["-Wno-cast-function-type"],
			'conditions': [
				['OS=="win"', {
					'defines': [],
					'include_dirs': [
					  'E:/opensource/boost_1_58_0_vs13'
					]
				}],
                ['OS=="linux"', {
					"link_settings": {
                        "libraries": [ '-lrt' ],
                    }
				}]
			]
        }
    ]
}