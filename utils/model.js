.pragma library

function stringify(model) {
    let data = []
    for (let i = 0; i < model.count; i++) {
        data.push(model.get(i))
    }
    return JSON.stringify(data, null, 2)
}
