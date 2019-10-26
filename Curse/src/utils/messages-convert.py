import sys
import os

def DelayedExit():
    time.sleep(2)
    sys.exit()

def StripRemark(s):
  rm = s.find('//')
  if rm >= 0:
    s= s[:rm]
  return s.strip()

def  GetLabel(s):
  if '[]' in s:
    return s[s[:s.find('[]')].rfind(' ')+1:s.find('[]')]
  else:
    return ''

def GetMessage(s):
  msg = ''
  esc = False
  b = s.find('"')
  e = s.rfind('"')
  if e-b > 0:
    for i in range(b+1,e):
      if esc:
        if s[i] == 'n':
          msg = msg + "'\\n',"
        else:  
          msg = msg + "'{}',".format(s[i])
        esc = False
      elif s[i] == '\\':
        esc = True
      else:
        if s[i] == "'":
          msg = msg + "'\\'',"
        else:
          msg = msg + "'{}',".format(s[i])
    if msg != '':
      #msg+='0x00,'
      msg = msg[0:-1] + ' + 0x80,'
  return msg
    
################################################################################

if len(sys.argv) != 2 :
    print("\nUsage: {} filename\n".format(os.path.basename(sys.argv[0])))
    DelayedExit()
    
filename = os.path.abspath(sys.argv[1])    
with open(filename,"r") as file:
  lines = file.readlines()
  file.close()
labels = []
messages = []
for line in lines:
  line = StripRemark(line)
  label = GetLabel(line)
  msg = GetMessage(line)
  if (label != '') and (msg != ''):
    labels.append(label)
    messages.append(msg)
if len(labels) < 255:
  type ="constexpr uint8_t"
else:
  type ="constexpr uint16_t"  
with open(os.path.dirname(filename)+os.sep+'messages-constants.h','w') as file:
  file.write('#pragma once\n\n// Imported {} messages from "{}"\n\n'.format(len(messages),os.path.basename(sys.argv[1])))
  for i in range (len(labels)):
    file.write('{} {}_Idx = {};\n'.format(type,labels[i],i))
  file.write('\nconst uint8_t messages[] PROGMEM = {\n')
  for i in range (len(messages)):
    file.write('{}\n'.format(messages[i]))
  file.write('};\n')
  file.close()