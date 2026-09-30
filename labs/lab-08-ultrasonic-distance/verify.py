#!/usr/bin/env python3
from pathlib import Path
import sys
p=Path(__file__).parent/'solution'/'ultrasonic_distance.ino'
text=p.read_text(encoding='utf-8')
required=['setup', 'loop', 'pinMode', 'Serial', 'digitalWrite', 'pulseIn']
missing=[x for x in required if x not in text]
if text.count('{') != text.count('}'): missing.append('balanced braces')
if missing:
    print('FAIL:', ', '.join(missing)); sys.exit(1)
print('PASS: ultrasonic_distance.ino contains the expected Lab 8 mechanisms')
