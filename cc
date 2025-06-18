function Dark() {
  var element = document.body;
  element.classList.toggle("dark-mode");
  if (element.classList.contains("dark-mode")) {
    console.log("Dark mode is enabled");
  } else {
    console.log("Dark mode is disabled");
  }
}

function updateCartCount() {
  const cart = JSON.parse(localStorage.getItem('cart')) || [];
  const totalItems = cart.reduce((sum, item) => sum + item.quantity, 0);
  const counter = document.getElementById('ItemCounter');
  if (counter) counter.innerText = totalItems;
}

function counter(event) {
  const button = event.target;
  const product = button.closest('.card');
  const title = product.querySelector('h3').innerText;
  const priceText = product.querySelector('p').innerText;
  const price = parseFloat(priceText.replace(/[^\d,.-]/g, '').replace(',', '.'));
  const image = product.querySelector('img').getAttribute('src');

  let cart = JSON.parse(localStorage.getItem('cart')) || [];

  const existing = cart.find(item => item.title === title);
  if (existing) {
    existing.quantity += 1;
  } else {
    cart.push({ title, price, image, quantity: 1 });
  }

  localStorage.setItem('cart', JSON.stringify(cart));
  updateCartCount();
}

function renderProducts(productArray) {
  const container = document.getElementById("product-grid");
  container.innerHTML = "";

  productArray.forEach(product => {
    const card = document.createElement("div");
    card.classList.add("card");

    card.innerHTML = `
      <img class="productimg" src="${product.imgSrc}" alt="${product.name}" />
      <h3>${product.name}</h3>
      <ul class="product-details">
        ${product.description.map(item => `<li>${item}</li>`).join('')}
      </ul>
      <p>Prijs: € ${product.price.toFixed(2)}</p>
      <button class="card__button">Add to Cart</button>
      <button class="del"><p class="delete-text">Delete</p></button>
    `;

    container.appendChild(card);
  });

  document.querySelectorAll('.card__button').forEach(button =>
    button.addEventListener('click', counter)
  );

  document.querySelectorAll('.del').forEach(button => {
    button.addEventListener('click', (event) => {
      const card = event.target.closest('.card');
      const title = card.querySelector('h3').innerText;
      let cart = JSON.parse(localStorage.getItem('cart')) || [];
      cart = cart.filter(item => item.title !== title);
      localStorage.setItem('cart', JSON.stringify(cart));
      updateCartCount();

      });
  });
}

const products = [
  {
    brand: "EDGE",
    type: "versterker",
    name: "EDGE EA800.5 Versterker",
    description: [
      "5-kanaals versterker",
      "Max. vermogen: 800 Watt",
      "Class D technologie",
      "Variabele lage doorlaatfilter"
    ],
    price: 499.00,
    imgSrc: "img/edge_amplifier.png"
  },
  {
    brand: "VIBE",
    type: "speakers",
    name: "VIBE BlackAir 6\" Component Speakers",
    description: [
      "6 inch component set",
      "120 Watt RMS vermogen",
      "Hoogwaardige geluidspreiding",
      "Inclusief tweeters"
    ],
    price: 179.99,
    imgSrc: "img/vibe_speakers.png"
  },
  {
    brand: "Hertz",
    type: "subwoofer",
    name: "Hertz ES 300.5 Subwoofer",
    description: [
      "12 inch subwoofer",
      "Maximaal vermogen: 600 Watt",
      "Dubbele spoel",
      "Hoog rendement"
    ],
    price: 329.00,
    imgSrc: "img/hertz_subwoofer.png"
  },
  {
    brand: "Pioneer",
    type: "headunit",
    name: "Pioneer DEH-S5200BT Autoradio",
    description: [
      "Bluetooth & USB ondersteuning",
      "High-Resolution Audio",
      "Anti-diefstal beveiliging",
      "Compatibel met Spotify"
    ],
    price: 149.95,
    imgSrc: "img/pioneer_headunit.png"
  },
  {
    brand: "EDGE",
    type: "subwoofer",
    name: "EDGE ED12D2 Subwoofer",
    description: [
      "12 inch subwoofer",
      "Dual voice coil",
      "RMS vermogen 600W",
      "Robuuste constructie"
    ],
    price: 299.00,
    imgSrc: "img/edge_subwoofer.png"
  },
  {
    brand: "VIBE",
    type: "versterker",
    name: "VIBE Slick 5-Kanaals Versterker",
    description: [
      "5-kanaals klasse D versterker",
      "Max. vermogen 1000 Watt",
      "Compact ontwerp",
      "Lage vervorming"
    ],
    price: 399.00,
    imgSrc: "img/vibe_amplifier.png"
  },
  {
    brand: "Hertz",
    type: "speakers",
    name: "Hertz DCX 165.3 Component Set",
    description: [
      "6.5 inch component speakers",
      "120 Watt RMS vermogen",
      "Koolstofvezel conus",
      "Inclusief crossover"
    ],
    price: 219.00,
    imgSrc: "img/hertz_speakers.png"
  },
  {
    brand: "Pioneer",
    type: "subwoofer",
    name: "Pioneer TS-WX130DA Actieve Subwoofer",
    description: [
      "13 cm actieve subwoofer",
      "Max. vermogen 150 Watt",
      "Lichtgewicht design",
      "Ingebouwde versterker"
    ],
    price: 149.99,
    imgSrc: "img/TS-WX130DA_1.png"
  },
  {
    brand: "VIBE",
    type: "subwoofer pakket",
    name: "VIBE SLICKMIT12T-V3 Subwoofer Pakket",
    description: [
      "Inclusief Bas Regelunit",
      "Inclusief kabelset",
      "Dubbele 12\" Subwoofer",
      "1200W RMS Versterker"
    ],
    price: 812.97,
    imgSrc: "img/2802387793-Ontwerpzondertitel1.png"
  },
  {
    brand: "VIBE",
    type: "woofers",
    name: "VIBE SLICKMIT12T-V3 Wooferset",
    description: [
      "Maat: 16.5 cm",
      "Per set / 2 stuks",
      "Impedantie: 4 Ω",
      "2 x 140 Watt RMS",
      "Woofers"
    ],
    price: 129.99,
    imgSrc: "img/1165790790-BA6MW-V41.png"
  },
  {
    brand: "EDGE",
    type: "componentenset",
    name: "EDGE EDBX6C-E1",
    description: [
      "Maat: 16.5 cm",
      "Per set / 2 stuks",
      "2-weg Componenten Set",
      "2 x 90 Watt RMS",
      "Impedantie: 4 Ω"
    ],
    price: 79.99,
    imgSrc: "img/2497511236-bg_edbx6c-e1.jpg"
  },
  {
    brand: "Pioneer",
    type: "headunit",
    name: "Pioneer SPH-DA97DAB-UNI",
    description: [
      "Android Auto & Apple Carplay",
      "9\" Zwevend Touchscreen",
      "Split Screen functie",
      "1-DIN Inbouwkit",
      "Direct Key & PxLink App"
    ],
    price: 799.00,
    imgSrc: "img/1339934757-1520419105-sph-da97dabantenne.png"
  },
  {
    brand: "EDGE",
    type: "versterker",
    name: "EDGE EDS3000.1FD-E3",
    description: [
      "Mono versterker",
      "1 x 3300 Watt @ 1Ω",
      "1 x 2050 Watt @ 2Ω",
      "1 x 1100 Watt @ 4Ω",
      "Full bridge technologie",
      "Ultra efficiënte class D topologie"
    ],
    price: 399.00,
    imgSrc: "img/edge_eds3000_1fd_e3.png"
  },
  {
    brand: "VIBE",
    type: "speakers",
    name: "VIBE OPTIVWT6-V9",
    description: [
      "Plug-and-play speaker upgrade kit voor VW T6",
      "Frequentierespons: 54Hz - 25kHz",
      "Piekvermogen: 270 Watt",
      "Eenvoudige installatie met alle benodigde componenten"
    ],
    price: 199.00,
    imgSrc: "img/vibe_optivwt6_v9.png"
  },
  {
    brand: "Hertz",
    type: "subwoofer",
    name: "Hertz SS 12 D2",
    description: [
      "12\" subwoofer",
      "2000W piekvermogen",
      "75 mm dual voice coil",
      "Versterkte ophanging",
      "Niet-geperste papieren conus"
    ],
    price: 299.00,
    imgSrc: "img/hertz_ss_12_d2.png"
  },
  {
    brand: "Pioneer",
    type: "headunit",
    name: "Pioneer SPH-DA97DAB-C-D7",
    description: [
      "9-inch multimedia-autoradio",
      "Speciaal ontworpen voor Fiat Ducato, Peugeot Boxer en Citroën Jumper (2007-2024)",
      "Inclusief Camper Navigatie-app met voertuigafhankelijke routering",
      "Draadloos en bedraad Apple CarPlay en Android Auto",
      "DAB+ radio, Bluetooth en Wi-Fi"
    ],
    price: 1049.00,
    imgSrc: "img/pioneer_sph_da97dab_c_d7.png"
  },
  {
    brand: "VIBE",
    type: "speakers",
    name: "VIBE BDPRO6M-V9",
    description: [
      "6.5\" Midrange Speaker",
      "175 Watt RMS @ 4Ω",
      "Semi-geperste papieren conus",
      "Hoge gevoeligheid en lage bewegingsmassa"
    ],
    price: 89.00,
    imgSrc: "img/vibe_bdpro6m_v9.png"
  },
  {
    brand: "Hertz",
    type: "subwoofer",
    name: "Hertz diECi DBA 201 F",
    description: [
      "Compacte underseat subwoofer",
      "220 Watt RMS",
      "Ingebouwde 440 W D-klasse versterker",
      "Superplat ontwerp",
      "Dubbele passieve radiatoren"
    ],
    price: 349.00,
    imgSrc: "img/hertz_dba_201_f.png"
  }
];

window.addEventListener('DOMContentLoaded', () => {
  updateCartCount();
  renderProducts(products);

  const brandFilter = document.getElementById("brandFilter");
  if (brandFilter) {
    brandFilter.addEventListener("change", () => {
      const selectedBrand = brandFilter.value;

      if (selectedBrand === "all") {
        renderProducts(products);
      } else {
        const filtered = products.filter(product => product.brand === selectedBrand);
        renderProducts(filtered);
      }
    });
  }
});


