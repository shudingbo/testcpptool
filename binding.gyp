{
	'targets': [
		{
      'target_name': 'Test',
      'include_dirs':['./src/test','./src/include',"<!@(node -p \"require('node-addon-api').include\")"],
      'sources': [
          'src/test/hello.cc'
      ],
      'dependencies': [
          './src/addon1/addon1.gyp:addon1',
          './src/addon2/addon2.gyp:addon2'
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
