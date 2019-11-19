#!/bin/bash

PYTHONPATH=src:lib pytest --junit-xml=test/report.xml test/test_regression.py
