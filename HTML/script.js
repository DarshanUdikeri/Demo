function currentTime(){
    const date = new Date()
    let hour = date.getHours()
    let minute = date.getMinutes()
    let second = date.getSeconds()

    let time = `${hour} : ${minute} : ${second}`
    console.log(time)

    // updateTime()
// convert this clock into AM and PM 
    document.getElementbyId("clock").innerText = time 
}

currentTime()
setInterval(currentTime,1000)
