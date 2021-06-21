rd /s /q lanShan
md lanShan
git clone https://github.com/huangshangbin/LanShanLibrary.git
xcopy LanShanLibrary\LanShanLibrary\LanShanLibrary\lanShan\*.* lanShan /y /e

rd /s /q LanShanLibrary

echo "update complete"
pause