let selectedItems = {};

function addToSelection(cubeId, cubeName) {
    if (selectedItems[cubeId]) {
        selectedItems[cubeId].count++;
    } else {
        selectedItems[cubeId] = { name: cubeName, count: 1 };
    }

    updateSelectionUI();

    if (typeof Module !== 'undefined' && Module._add_cube_to_logic) {
        Module._add_cube_to_logic(cubeId);
    }
}

function updateSelectionUI() {
    const container = document.getElementById('archived-items');
    if (!container) return;
    
    container.innerHTML = '';

    for (let id in selectedItems) {
        const item = selectedItems[id];
        
        const itemDiv = document.createElement('div');
        itemDiv.className = 'archived-item';
        itemDiv.innerText = item.name;

        if (item.count > 1) {
            const countDiv = document.createElement('div');
            countDiv.className = 'item-count';
            countDiv.innerText = item.count;
            itemDiv.appendChild(countDiv);
        }

        container.appendChild(itemDiv);
    }
}

function initializeSimulation() {
    if (typeof Module !== 'undefined' && Module._start_simulation) {
        Module._start_simulation();
    }
}
