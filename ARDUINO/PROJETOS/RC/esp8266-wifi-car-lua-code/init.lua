wifi.setmode(wifi.SOFTAP)

cfg={}
cfg.ssid="mywifi"
cfg.pwd="qwerty123"

cfg.ip="192.168.0.1"
cfg.netmask="255.255.255.0"
cfg.gateway="192.168.0.1"

port = 9876

wifi.ap.setip(cfg)
wifi.ap.config(cfg)

function stringStarts(a,b)
    return string.sub(a,1,string.len(b))==b
end

function stringEnds(a,b)
   return b=='' or string.sub(a,-string.len(b))==b
end

chCount = 2
chPin = {3, 4} -- GPIO 0, 2
chVal = {1500, 1500}

cmd = ""

for i=1, chCount do
    gpio.mode(chPin[i],gpio.OUTPUT)
    gpio.write(chPin[i],gpio.LOW)
end

pwmEn = 0 -- disabled until connect

tmr.alarm(0,20,1,function() -- 50 Hz
    if pwmEn==1 then
        for i=1, chCount do
            if chVal[i] then -- if valid val
                -- gen pulse
                gpio.write(chPin[i], gpio.HIGH)
                tmr.delay(chVal[i]*0.893921) -- with correction
                gpio.write(chPin[i], gpio.LOW)
            end
        end
    end
end)


function exeCmd(st) -- ex: "ch0 1500"

    tmr.stop(1) -- clr contact lost tmr
    pwmEn = 1
    
    tmr.alarm(1,500,0,function() -- if cnt lost for 500ms
        pwmEn = 0
    end)
    
    if stringStarts(st, "c") then
        ch = tonumber( string.sub(st, 3, 3) ) + 1
        val = tonumber( string.sub(st, 5, string.len(st) ) )
    end
    
    if stringStarts(st, "ch") then chVal[ch] = val end  
    if stringStarts(st, "ci") then chVal[ch] = -val end   
    if stringStarts(st, "ca") then chVal[ch] = 1500 + val*51 end  
    if stringStarts(st, "cb") then chVal[ch] = 1500 - val*51 end
end


function receiveData(conn, data)
    cmd = cmd .. data

    local a, b = string.find(cmd, "\n", 1, true)   
    while a do
        exeCmd( string.sub(cmd, 1, a-1) )
        cmd = string.sub(cmd, a+1, string.len(cmd))
        a, b = string.find(cmd, "\n", 1, true)
    end 
end


print("ESP8266 RC receiver 1.0 powered by RoboRemo")
print("SSID: " .. cfg.ssid .. "  PASS: " .. cfg.pwd)
print("RoboRemo app must connect to " .. cfg.ip .. ":" .. port)

srv=net.createServer(net.TCP, 28800) 
srv:listen(port,function(conn)
    print("RoboRemo connected")
     
    conn:on("receive",receiveData)  
    
    conn:on("disconnection",function(c) 
        print("RoboRemo disconnected")
    end)
    
end)
