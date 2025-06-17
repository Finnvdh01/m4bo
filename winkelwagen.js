function loadCart() {
  const cart = JSON.parse(localStorage.getItem('cart')) || [];
  const container = document.getElementById('cart-container');
  const totalDiv = document.getElementById('total-price');
  container.innerHTML = '';
  totalDiv.innerHTML = '';

  if (cart.length === 0) {
    container.innerHTML = '<p>Je winkelwagen is leeg.</p>';
    return;
  }

  let total = 0;

  cart.forEach((item, index) => {
    const itemTotal = item.price * item.quantity;
    total += itemTotal;

    const product = document.createElement('div');
    product.className = 'cart-item';
    product.innerHTML = `
      <img src="${item.image}" alt="${item.title}" width="100" />
      <div>
        <h3>${item.title}</h3>
        <p>Prijs: €${item.price.toFixed(2)}</p>
        <p>Aantal: ${item.quantity}</p>
        <p>Totaal: €${itemTotal.toFixed(2)}</p>
        <button onclick="removeItem(${index})">Verwijder</button>
      </div>
    `;

    container.appendChild(product);
  });

  totalDiv.innerHTML = `<h2>Subtotaal: €${total.toFixed(2)}</h2>`;
}

function removeItem(index) {
  const cart = JSON.parse(localStorage.getItem('cart')) || [];
  cart.splice(index, 1);
  localStorage.setItem('cart', JSON.stringify(cart));
  loadCart();
}

window.onload = loadCart;
