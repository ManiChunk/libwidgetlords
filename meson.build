project('libwidgetlords', 'c', default_options: '-std=c11')

pkg = import('pkgconfig')

cc = meson.get_compiler('c')

# add -lm
m_dep = cc.find_library('m', required : false)

#wiringpi = dependency('wiringPi')
# meson still can't locate wiringPi using regular methods
wiringpi = cc.find_library('wiringPi')

include = include_directories('include')
source = [
  'src/helpers.c',
  'src/pi_spi.c',
  'src/pi_spi_2ao.c',
  'src/pi_spi_8ai.c',
  'src/pi_spi_8di.c',
  'src/pi_spi_8ko.c',
  'src/pi_spi_din.c',
  'src/pi_spi_din_8ai.c',
  'src/pi_spi_din_8di.c',
  'src/pi_spi_din_4ko.c',
  'src/pi_spi_din_4ao.c',
  'src/vpe_2901a.c',
  'src/sdafe.c',
  'src/vpe_3011b.c',
  'src/spi.c'
]
lib = library('widgetlords',
              source,
              dependencies: [m_dep, wiringpi],
              install: true,
              include_directories: include,
              version: '1.0.2')

install_headers('include/pi_spi.h', 'include/pi_spi_din.h', 'include/widgetlords.h', subdir: 'widgetlords')

install_data('libwidgetlords.vapi', install_dir: 'share/vala/vapi')

dep = declare_dependency(include_directories: include, link_with: lib)

pkg.generate(libraries: [lib], 
             version: '1.0.2', 
             name: 'libwidgetlords',
             description: 'libwidgetlords',
             subdirs: ['widgetlords'])

if get_option('python')
  # maybe one day
  #py = import('python3')
  #message(py.sysconfig_path())
  
  message('Getting python install dir')
  r = run_command('python3', '-c', 'from distutils.sysconfig import get_python_lib; print(get_python_lib())')
  if r.returncode() != 0
    error('Cannot find python install dir')
  endif
  python_dir = r.stdout().strip()
  message(python_dir)

  install_data('python/widgetlords/__init__.py',
               'python/widgetlords/pi_spi.py', 
               'python/widgetlords/pi_spi_din.py', 
               install_dir: join_paths(python_dir, 'widgetlords'))
endif

executable('pi_spi_8ko_demo', 'src/pi_spi_8ko_demo.c', dependencies: [dep])
executable('pi_spi_8ai_demo', 'src/pi_spi_8ai_demo.c', dependencies: [dep])
executable('pi_spi_8di_demo', 'src/pi_spi_8di_demo.c', dependencies: [dep])
executable('pi_spi_2ao_demo', 'src/pi_spi_2ao_demo.c', dependencies: [dep])

executable('pi_spi_din_4ko_demo', 'src/pi_spi_din_4ko_demo.c', dependencies: [dep])
executable('pi_spi_din_8ai_demo', 'src/pi_spi_din_8ai_demo.c', dependencies: [dep])
executable('pi_spi_din_8ai_mademo', 'src/pi_spi_din_8ai_mademo.c', dependencies: [dep])
executable('pi_spi_din_8ai_10vdemo', 'src/pi_spi_din_8ai_10vdemo.c', dependencies: [dep])
executable('pi_spi_din_8ai_thermdemo', 'src/pi_spi_din_8ai_thermdemo.c', dependencies: [dep])
executable('pi_spi_din_8di_demo', 'src/pi_spi_din_8di_demo.c', dependencies: [dep])
executable('pi_spi_din_4ao_demo', 'src/pi_spi_din_4ao_demo.c', dependencies: [dep])
executable('vpe_2901a_demo', 'src/vpe_2901a_demo.c', dependencies: [dep])
executable('vpe_3011b_demo', 'src/vpe_3011b_demo.c', dependencies: [dep])
