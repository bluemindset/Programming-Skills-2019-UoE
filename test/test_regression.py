import unittest
from regression import Reg_Lib
from test import support
import sys


#Regression tests class 

class TestRegression(unittest.TestCase):
	
	"""
	Compile every testcase for Version 1 and Version 2
	setUp func: https://docs.python.org/3.4/library/test.html
	"""
	def setUp(self):
		reg_lib = Reg_Lib()

		#Compile and run all the instances of version 1
		reg_lib.compile_v1()
		reg_lib.run_v1()

		#Compile and run all the instances of version 2
		reg_lib.compile_v2()
		reg_lib.run_v2()
			

	"""
	Clean up every testcase for Version 1 and Version 2
	tearDown func: https://docs.python.org/3.4/library/test.html
	"""
   	def tearDown(self):
		reg_lib = Reg_Lib()

		#Clean object, executables of all the instances of version 1
		reg_lib.clean_v1()

		#Clean object, executables of all the instances of version 1
		reg_lib.clean_v2()
	   	   

	def test_stdout_file(self):
		regression = Reg_Lib()
		
		for v1,v2 in zip(Reg_Lib._versions_1,Reg_Lib._versions_2):
			
			stdout_v1 = Reg_Lib._test_dir+ "/"+v1+"/"+Reg_Lib._output_dir+ "/"+ Reg_Lib._stdout_file
			stdout_v2 = Reg_Lib._test_dir+ "/"+v2+"/"+Reg_Lib._output_dir+ "/"+ Reg_Lib._stdout_file

			self.assertEqual(regression.get_output(stdout_v1),
								regression.get_output(stdout_v2)
								,msg="Version 1 and Version 2 standard (screen) output are not the same!")
	def test_pgm_file(self):
		regression = Reg_Lib()
		
		for v1,v2 in zip(Reg_Lib._versions_1,Reg_Lib._versions_2):
			
			pgm_file_v1  = 	Reg_Lib._test_dir+ "/"+v1+"/"+Reg_Lib._output_dir+ "/"+ Reg_Lib._pgm_file
			pgm_file_v2  = 	Reg_Lib._test_dir+ "/"+v2+"/"+Reg_Lib._output_dir+ "/"+ Reg_Lib._pgm_file

			self.assertEqual(regression.get_output(pgm_file_v1),
								regression.get_output(pgm_file_v2)
								,msg="Version 1 and Version 2 pgm file output are not the same!")
	
	def test_dat_file(self):
		regression = Reg_Lib()
		
		for v1,v2 in zip(Reg_Lib._versions_1,Reg_Lib._versions_2):
			
			dat_file_v1 = Reg_Lib._test_dir+ "/"+v1+"/"+Reg_Lib._output_dir+ "/"+ Reg_Lib._dat_file
			dat_file_v2 = Reg_Lib._test_dir+ "/"+v2+"/"+Reg_Lib._output_dir+ "/"+ Reg_Lib._dat_file

			self.assertEqual(regression.get_output(dat_file_v1),
								regression.get_output(dat_file_v2)
								,msg="Version 1 and Version 2 dat file output are not the same!")
							


if __name__ == '__main__': 
	unittest.main()
